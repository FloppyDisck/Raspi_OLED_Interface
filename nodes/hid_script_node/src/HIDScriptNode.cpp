#include "scriptmod/HIDScriptNode.hpp"

std::string HID_EMPTY = "\\0";
std::string HID_PACKET_PREFIX = "\\x";
std::string HID_PACKET_TRAIL = "\\0\\0\\0\\0\\0";
std::string HID_EMPTY_PACKET = "\\0\\0\\0\\0\\0\\0\\0\\0";

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

std::string char2HID(char c) {
    int hid_num;

    std::string mod = HID_EMPTY;
    std::string hid;

    switch (c) {
        case '!':
            hid_num = (int)KEYBD_1;
            mod = n2hexstr(int(KEYBD_MOD_LSHIFT));
            break;
        case '"':
            hid_num = (int)KEYBD_APOSTROPHE;
            mod = n2hexstr(int(KEYBD_MOD_LSHIFT));
            break;
        case '#':
            hid_num = (int)KEYBD_3;
            mod = n2hexstr(int(KEYBD_MOD_LSHIFT));
            break;
        case '$':
            hid_num = (int)KEYBD_4;
            mod = n2hexstr(int(KEYBD_MOD_LSHIFT));
            break;
        case '%':
            hid_num = (int)KEYBD_5;
            mod = n2hexstr(int(KEYBD_MOD_LSHIFT));
            break;
        case '&':
            hid_num = (int)KEYBD_7;
            mod = n2hexstr(int(KEYBD_MOD_LSHIFT));
            break;
        case '\'':
            hid_num = (int)KEYBD_APOSTROPHE;
            break;
        case '(':
            hid_num = (int)KEYBD_9;
            mod = n2hexstr(int(KEYBD_MOD_LSHIFT));
            break;
        case ')':
            hid_num = (int)KEYBD_0;
            mod = n2hexstr(int(KEYBD_MOD_LSHIFT));
            break;
        case '*':
            hid_num = (int)KEYBD_8;
            mod = n2hexstr(int(KEYBD_MOD_LSHIFT));
            break;
        case '+':
            hid_num = (int)KEYBD_EQUAL;
            mod = n2hexstr(int(KEYBD_MOD_LSHIFT));
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
            mod = n2hexstr(int(KEYBD_MOD_LSHIFT));
            break;
        case ';':
            hid_num = (int)KEYBD_SEMICOLON;
            break;
        case '<':
            hid_num = (int)KEYBD_COMMA;
            mod = n2hexstr(int(KEYBD_MOD_LSHIFT));
            break;
        case '=':
            hid_num = (int)KEYBD_EQUAL;
            break;
        case '>':
            hid_num = (int)KEYBD_DOT;
            mod = n2hexstr(int(KEYBD_MOD_LSHIFT));
            break;
        case '?':
            hid_num = (int)KEYBD_SLASH;
            mod = n2hexstr(int(KEYBD_MOD_LSHIFT));
            break;
        case '@':
            hid_num = (int)KEYBD_2;
            mod = n2hexstr(int(KEYBD_MOD_LSHIFT));
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
            mod = n2hexstr(int(KEYBD_MOD_LSHIFT));
            break;
        case '_':
            hid_num = (int)KEYBD_MINUS;
            mod = n2hexstr(int(KEYBD_MOD_LSHIFT));
            break;
        case '`':
            hid_num = (int)KEYBD_GRAVE;
            break;
        case '{':
            hid_num = (int)KEYBD_LEFTBRACE;
            mod = n2hexstr(int(KEYBD_MOD_LSHIFT));
            break;
        case '|':
            hid_num = (int)KEYBD_BACKSLASH;
            mod = n2hexstr(int(KEYBD_MOD_LSHIFT));
            break;
        case '}':
            hid_num = (int)KEYBD_RIGHTBRACE;
            mod = n2hexstr(int(KEYBD_MOD_LSHIFT));
            break;
        case '~':
            hid_num = (int)KEYBD_GRAVE;
            mod = n2hexstr(int(KEYBD_MOD_LSHIFT));
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
                mod = n2hexstr(int(KEYBD_MOD_LSHIFT));
            }
            // a-z
            else if (ascii >= 97 && ascii <= 122) {
                hid_num = KEYBD_A + ascii - 65;
            }
    }

    return mod + HID_EMPTY + n2hexstr(hid_num) + HID_EMPTY + HID_PACKET_TRAIL;
}

HIDScriptNode::HIDScriptNode(const char *name, Node *previous, ModProbeItem *modprobe) :
Node(name, previous), modprobe(modprobe){}

Node * HIDScriptNode::input(int input) {
    std::string word = "Hello, testing, testing";

    std::cout << "Testing modprobe" << std::endl;

    if (modprobe->getState() == 2) {
        for (char& c : word) {
            std::cout << c << std::endl;
            std::string keypress = char2HID(c);
            std::cout << keypress << std::endl;
            std::string command = "echo -ne \"" + keypress + "\" | sudo tee /dev/hidg0";
            system(command.c_str());
            //modprobe->HID_OUT << keypress;
            //modprobe->HID_OUT << HID_EMPTY_PACKET;
        }
    }
    std::string command = "echo -ne \"" + HID_EMPTY_PACKET + "\" | sudo tee /dev/hidg0";
    system(command.c_str());

    return previous_;
}

void HIDScriptNode::draw() { }