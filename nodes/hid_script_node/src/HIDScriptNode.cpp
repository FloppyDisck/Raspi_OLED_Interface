#include <sstream>
#include "scriptmod/HIDScriptNode.hpp"

std::string HID_EMPTY = "\0";
std::string HID_PACKET_PREFIX = "\\x";
std::string HID_PACKET_TRAIL = "\0\0\0\0\0";
std::string HID_EMPTY_PACKET = "\0\0\0\0\0\0\0\0";

// Supposed fast implementation of the "to string"
//template <typename I> std::string n2hexstr(I w, size_t hex_len) {
//    static const char* digits = "0123456789ABCDEF";
//    std::string rc(hex_len,'0');
//    for (size_t i=0, j=(hex_len-1)*4 ; i<hex_len; ++i,j-=4)
//        rc[i] = digits[(w>>j) & 0x0f];
//    return rc;
//}

//Custom implementation - string comes with prefix and locked at size 2
template <typename I> std::string n2hexstr(I w) {
    static const char* digits = "0123456789ABCDEF";
    std::string rc(4,'0');
    rc[0] = '\\';
    rc[1] = 'x';

    for (size_t i=2, j=4 ; i<4; ++i,j-=4)
        rc[i] = digits[(w>>j) & 0x0f];
    return rc;
}

char* char2HID(char c) {
    int hid_num;

    std::string mod = HID_EMPTY;
    char newMod = 0x00;
    std::string hid;

    switch (c) {
        case '!':
            hid_num = (int)KEYBD_1;
            newMod = KEYBD_MOD_LSHIFT;
            break;
        case '"':
            hid_num = (int)KEYBD_APOSTROPHE;
            newMod = KEYBD_MOD_LSHIFT;
            break;
        case '#':
            hid_num = (int)KEYBD_3;
            newMod = KEYBD_MOD_LSHIFT;
            break;
        case '$':
            hid_num = (int)KEYBD_4;
            newMod = KEYBD_MOD_LSHIFT;
            break;
        case '%':
            hid_num = (int)KEYBD_5;
            newMod = KEYBD_MOD_LSHIFT;
            break;
        case '&':
            hid_num = (int)KEYBD_7;
            newMod = KEYBD_MOD_LSHIFT;
            break;
        case '\'':
            hid_num = (int)KEYBD_APOSTROPHE;
            break;
        case '(':
            hid_num = (int)KEYBD_9;
            newMod = KEYBD_MOD_LSHIFT;
            break;
        case ')':
            hid_num = (int)KEYBD_0;
            newMod = KEYBD_MOD_LSHIFT;
            break;
        case '*':
            hid_num = (int)KEYBD_8;
            newMod = KEYBD_MOD_LSHIFT;
            break;
        case '+':
            hid_num = (int)KEYBD_EQUAL;
            newMod = KEYBD_MOD_LSHIFT;
            break;
        case ',':
            hid_num = (int)KEYBD_COMMA;
            break;
        case '-':
            hid_num = (int)KEYBD_MINUS;
            break;
        case '.':
            hid_num = (int)KEYBD_DOT;
            break;
        case '/':
            hid_num = (int)KEYBD_SLASH;
            break;
        case '0':
            hid_num = (int)KEYBD_0;
            break;
        case ':':
            hid_num = (int)KEYBD_SEMICOLON;
            newMod = KEYBD_MOD_LSHIFT;
            break;
        case ';':
            hid_num = (int)KEYBD_SEMICOLON;
            break;
        case '<':
            hid_num = (int)KEYBD_COMMA;
            newMod = KEYBD_MOD_LSHIFT;
            break;
        case '=':
            hid_num = (int)KEYBD_EQUAL;
            break;
        case '>':
            hid_num = (int)KEYBD_DOT;
            newMod = KEYBD_MOD_LSHIFT;
            break;
        case '?':
            hid_num = (int)KEYBD_SLASH;
            newMod = KEYBD_MOD_LSHIFT;
            break;
        case '@':
            hid_num = (int)KEYBD_2;
            newMod = KEYBD_MOD_LSHIFT;
            break;
        case '[':
            hid_num = (int)KEYBD_LEFTBRACE;
            break;
        case '\\':
            hid_num = (int)KEYBD_BACKSLASH;
            break;
        case ']':
            hid_num = (int)KEYBD_RIGHTBRACE;
            break;
        case '^':
            hid_num = (int)KEYBD_6;
            newMod = KEYBD_MOD_LSHIFT;
            break;
        case '_':
            hid_num = (int)KEYBD_MINUS;
            newMod = KEYBD_MOD_LSHIFT;
            break;
        case '`':
            hid_num = (int)KEYBD_GRAVE;
            break;
        case '{':
            hid_num = (int)KEYBD_LEFTBRACE;
            newMod = KEYBD_MOD_LSHIFT;
            break;
        case '|':
            hid_num = (int)KEYBD_BACKSLASH;
            newMod = KEYBD_MOD_LSHIFT;
            break;
        case '}':
            hid_num = (int)KEYBD_RIGHTBRACE;
            newMod = KEYBD_MOD_LSHIFT;
            break;
        case '~':
            hid_num = (int)KEYBD_GRAVE;
            newMod = KEYBD_MOD_LSHIFT;
            break;
        default:
            int ascii = (int)c;
            // Space
            if (ascii == 32) {
                hid_num = (int)KEYBD_SPACE;
            }
            // 1-9
            else if (ascii >= 49 && ascii <= 57) {
                hid_num = KEYBD_1 + ascii - 49;
            }
            // A-Z
            else if (ascii >= 65 && ascii <= 90) {
                hid_num = KEYBD_A + ascii - 65;
                newMod = KEYBD_MOD_LSHIFT;
            }
            // a-z
            else if (ascii >= 97 && ascii <= 122) {
                hid_num = KEYBD_A + ascii - 65;
            }
    }

    std::stringstream retStream;
    retStream << newMod << '\0' << hid_num << '\0' << '\0' << '\0' << '\0' << '\0';
    char buffer[8] = {newMod, 0x00, char(hid_num), 0x00, 0x00, 0x00, 0x00, 0x00};
    return buffer;
    //return retStream.str();
    //return mod + HID_EMPTY + n2hexstr(hid_num) + HID_EMPTY + HID_PACKET_TRAIL;
}

HIDScriptNode::HIDScriptNode(const char *name, Node *previous) :
Node(name, previous){}

Node * HIDScriptNode::input(int input) {
    using namespace std::chrono_literals; //For time prefixed

    std::string word = "Hello, testing, testing";

    std::cout << "Testing modprobe" << std::endl;

    std::ofstream HID_OUT;
    for (char& c : word) {
        std::cout << c << std::endl;
        char* keypress = char2HID(c);
        //std::string keypress = char2HID(c);
        //std::cout << keypress << std::endl;
//        std::string command = "echo -ne \"" + keypress + "\" | sudo tee /dev/hidg0";
        HID_OUT.open("/dev/hidg0", std::ios::binary);
        //HID_OUT << keypress;
        HID_OUT.write(keypress, 8);
        HID_OUT.close();
//        std::this_thread::sleep_for(100ms);
//        system(command.c_str());
//        command = "echo -ne \"" + HID_EMPTY_PACKET + "\" | sudo tee /dev/hidg0";
        HID_OUT.open("/dev/hidg0", std::ios::binary);
        //HID_OUT << HID_EMPTY_PACKET;
        char empty[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
        HID_OUT.write(empty, 8);
        HID_OUT.close();
//        std::this_thread::sleep_for(50ms);
//        system(command.c_str());
    }

    return previous_;
}

void HIDScriptNode::draw() { }