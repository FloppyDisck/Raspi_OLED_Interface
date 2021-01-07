#include "scriptmod/HIDScriptNode.hpp"

char HID_EMPTY[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

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
    char pressed_key;

    char mod = 0x00;
    std::string hid;

    switch (c) {
        case '!':
            pressed_key = KEYBD_1;
            mod = KEYBD_MOD_LSHIFT;
            break;
        case '"':
            pressed_key = KEYBD_APOSTROPHE;
            mod = KEYBD_MOD_LSHIFT;
            break;
        case '#':
            pressed_key = KEYBD_3;
            mod = KEYBD_MOD_LSHIFT;
            break;
        case '$':
            pressed_key = KEYBD_4;
            mod = KEYBD_MOD_LSHIFT;
            break;
        case '%':
            pressed_key = KEYBD_5;
            mod = KEYBD_MOD_LSHIFT;
            break;
        case '&':
            pressed_key = KEYBD_7;
            mod = KEYBD_MOD_LSHIFT;
            break;
        case '\'':
            pressed_key = KEYBD_APOSTROPHE;
            break;
        case '(':
            pressed_key = KEYBD_9;
            mod = KEYBD_MOD_LSHIFT;
            break;
        case ')':
            pressed_key = KEYBD_0;
            mod = KEYBD_MOD_LSHIFT;
            break;
        case '*':
            pressed_key = KEYBD_8;
            mod = KEYBD_MOD_LSHIFT;
            break;
        case '+':
            pressed_key = KEYBD_EQUAL;
            mod = KEYBD_MOD_LSHIFT;
            break;
        case ',':
            pressed_key = KEYBD_COMMA;
            break;
        case '-':
            pressed_key = KEYBD_MINUS;
            break;
        case '.':
            pressed_key = KEYBD_DOT;
            break;
        case '/':
            pressed_key = KEYBD_SLASH;
            break;
        case '0':
            pressed_key = KEYBD_0;
            break;
        case ':':
            pressed_key = KEYBD_SEMICOLON;
            mod = KEYBD_MOD_LSHIFT;
            break;
        case ';':
            pressed_key = KEYBD_SEMICOLON;
            break;
        case '<':
            pressed_key = KEYBD_COMMA;
            mod = KEYBD_MOD_LSHIFT;
            break;
        case '=':
            pressed_key = KEYBD_EQUAL;
            break;
        case '>':
            pressed_key = KEYBD_DOT;
            mod = KEYBD_MOD_LSHIFT;
            break;
        case '?':
            pressed_key = KEYBD_SLASH;
            mod = KEYBD_MOD_LSHIFT;
            break;
        case '@':
            pressed_key = KEYBD_2;
            mod = KEYBD_MOD_LSHIFT;
            break;
        case '[':
            pressed_key = KEYBD_LEFTBRACE;
            break;
        case '\\':
            pressed_key = KEYBD_BACKSLASH;
            break;
        case ']':
            pressed_key = KEYBD_RIGHTBRACE;
            break;
        case '^':
            pressed_key = KEYBD_6;
            mod = KEYBD_MOD_LSHIFT;
            break;
        case '_':
            pressed_key = KEYBD_MINUS;
            mod = KEYBD_MOD_LSHIFT;
            break;
        case '`':
            pressed_key = KEYBD_GRAVE;
            break;
        case '{':
            pressed_key = KEYBD_LEFTBRACE;
            mod = KEYBD_MOD_LSHIFT;
            break;
        case '|':
            pressed_key = KEYBD_BACKSLASH;
            mod = KEYBD_MOD_LSHIFT;
            break;
        case '}':
            pressed_key = KEYBD_RIGHTBRACE;
            mod = KEYBD_MOD_LSHIFT;
            break;
        case '~':
            pressed_key = KEYBD_GRAVE;
            mod = KEYBD_MOD_LSHIFT;
            break;
        default:
            int ascii = (int)c;
            // Space
            if (ascii == 32) {
                pressed_key = KEYBD_SPACE;
            }
            // 1-9
            else if (ascii >= 49 && ascii <= 57) {
                pressed_key = KEYBD_1 + ascii - 49;
            }
            // A-Z
            else if (ascii >= 65 && ascii <= 90) {
                pressed_key = KEYBD_A + ascii - 65;
                mod = KEYBD_MOD_LSHIFT;
            }
            // a-z
            else if (ascii >= 97 && ascii <= 122) {
                pressed_key = KEYBD_A + ascii - 97;
            }
    }

    char* buffer = new char[8]{mod, 0x00, pressed_key, 0x00, 0x00, 0x00, 0x00, 0x00};
    return buffer;
}

HIDScriptNode::HIDScriptNode(const char *name, Node *previous) :
Node(name, previous){}

Node * HIDScriptNode::input(int input) {
    using namespace std::chrono_literals; //For time prefixed

    std::string word = "Hello, testing, testing";

    std::ofstream HID_OUT;
    for (char& c : word) {
        std::cout << c << std::endl;
        char* keypress = char2HID(c);

        HID_OUT.open("/dev/hidg0", std::ios::binary);

        HID_OUT.write(keypress, 8);
        //HID_OUT.close();
//        std::this_thread::sleep_for(100ms);

        //HID_OUT.open("/dev/hidg0", std::ios::binary);
        HID_OUT.write(HID_EMPTY, 8);
        HID_OUT.close();
//        std::this_thread::sleep_for(50ms);

    }

    return previous_;
}

void HIDScriptNode::draw() { }