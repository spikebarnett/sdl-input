#include <string>

enum Input_Enum
{
  UNKNOWN = 0,
  K_A = 4,
  K_B = 5,
  K_C = 6,
  K_D = 7,
  K_E = 8,
  K_F = 9,
  K_G = 10,
  K_H = 11,
  K_I = 12,
  K_J = 13,
  K_K = 14,
  K_L = 15,
  K_M = 16,
  K_N = 17,
  K_O = 18,
  K_P = 19,
  K_Q = 20,
  K_R = 21,
  K_S = 22,
  K_T = 23,
  K_U = 24,
  K_V = 25,
  K_W = 26,
  K_X = 27,
  K_Y = 28,
  K_Z = 29,
  K_1 = 30,
  K_2 = 31,
  K_3 = 32,
  K_4 = 33,
  K_5 = 34,
  K_6 = 35,
  K_7 = 36,
  K_8 = 37,
  K_9 = 38,
  K_0 = 39,
  K_RETURN = 40,
  K_ESCAPE = 41,
  K_BACKSPACE = 42,
  K_TAB = 43,
  K_SPACE = 44,
  K_MINUS = 45,
  K_EQUALS = 46,
  K_LEFTBRACKET = 47,
  K_RIGHTBRACKET = 48,
  K_BACKSLASH = 49,
  K_SEMICOLON = 51,
  K_APOSTROPHE = 52,
  K_GRAVE = 53,
  K_COMMA = 54,
  K_PERIOD = 55,
  K_SLASH = 56,
  K_CAPSLOCK = 57,
  K_F1 = 58,
  K_F2 = 59,
  K_F3 = 60,
  K_F4 = 61,
  K_F5 = 62,
  K_F6 = 63,
  K_F7 = 64,
  K_F8 = 65,
  K_F9 = 66,
  K_F10 = 67,
  K_F11 = 68,
  K_F12 = 69,
  K_PRINTSCREEN = 70,
  K_SCROLLLOCK = 71,
  K_PAUSE = 72,
  K_INSERT = 73,
  K_HOME = 74,
  K_PAGEUP = 75,
  K_DELETE = 76,
  K_END = 77,
  K_PAGEDOWN = 78,
  K_RIGHT = 79,
  K_LEFT = 80,
  K_DOWN = 81,
  K_UP = 82,
  K_NUMLOCKCLEAR = 83,
  K_KP_DIVIDE = 84,
  K_KP_MULTIPLY = 85,
  K_KP_MINUS = 86,
  K_KP_PLUS = 87,
  K_KP_ENTER = 88,
  K_KP_1 = 89,
  K_KP_2 = 90,
  K_KP_3 = 91,
  K_KP_4 = 92,
  K_KP_5 = 93,
  K_KP_6 = 94,
  K_KP_7 = 95,
  K_KP_8 = 96,
  K_KP_9 = 97,
  K_KP_0 = 98,
  K_KP_PERIOD = 99,
  K_APPLICATION = 101,
  K_POWER = 102,
  K_KP_EQUALS = 103,
  K_F13 = 104,
  K_F14 = 105,
  K_F15 = 106,
  K_F16 = 107,
  K_F17 = 108,
  K_F18 = 109,
  K_F19 = 110,
  K_F20 = 111,
  K_F21 = 112,
  K_F22 = 113,
  K_F23 = 114,
  K_F24 = 115,
  K_EXECUTE = 116,
  K_HELP = 117,
  K_MENU = 118,
  K_SELECT = 119,
  K_STOP = 120,
  K_AGAIN = 121,
  K_UNDO = 122,
  K_CUT = 123,
  K_COPY = 124,
  K_PASTE = 125,
  K_FIND = 126,
  K_MUTE = 127,
  K_VOLUMEUP = 128,
  K_VOLUMEDOWN = 129,
  K_KP_COMMA = 133,
  K_KP_EQUALSAS400 = 134,
  K_ALTERASE = 153,
  K_SYSREQ = 154,
  K_CANCEL = 155,
  K_CLEAR = 156,
  K_PRIOR = 157,
  K_RETURN2 = 158,
  K_SEPARATOR = 159,
  K_OUT = 160,
  K_OPER = 161,
  K_CLEARAGAIN = 162,
  K_CRSEL = 163,
  K_EXSEL = 164,
  K_KP_00 = 176,
  K_KP_000 = 177,
  K_THOUSANDSSEPARATOR = 178,
  K_DECIMALSEPARATOR = 179,
  K_CURRENCYUNIT = 180,
  K_CURRENCYSUBUNIT = 181,
  K_KP_LEFTPAREN = 182,
  K_KP_RIGHTPAREN = 183,
  K_KP_LEFTBRACE = 184,
  K_KP_RIGHTBRACE = 185,
  K_KP_TAB = 186,
  K_KP_BACKSPACE = 187,
  K_KP_A = 188,
  K_KP_B = 189,
  K_KP_C = 190,
  K_KP_D = 191,
  K_KP_E = 192,
  K_KP_F = 193,
  K_KP_XOR = 194,
  K_KP_POWER = 195,
  K_KP_PERCENT = 196,
  K_KP_LESS = 197,
  K_KP_GREATER = 198,
  K_KP_AMPERSAND = 199,
  K_KP_DBLAMPERSAND = 200,
  K_KP_VERTICALBAR = 201,
  K_KP_DBLVERTICALBAR = 202,
  K_KP_COLON = 203,
  K_KP_HASH = 204,
  K_KP_SPACE = 205,
  K_KP_AT = 206,
  K_KP_EXCLAM = 207,
  K_KP_MEMSTORE = 208,
  K_KP_MEMRECALL = 209,
  K_KP_MEMCLEAR = 210,
  K_KP_MEMADD = 211,
  K_KP_MEMSUBTRACT = 212,
  K_KP_MEMMULTIPLY = 213,
  K_KP_MEMDIVIDE = 214,
  K_KP_PLUSMINUS = 215,
  K_KP_CLEAR = 216,
  K_KP_CLEARENTRY = 217,
  K_KP_BINARY = 218,
  K_KP_OCTAL = 219,
  K_KP_DECIMAL = 220,
  K_KP_HEXADECIMAL = 221,
  K_LCTRL = 224,
  K_LSHIFT = 225,
  K_LALT = 226,
  K_LGUI = 227,
  K_RCTRL = 228,
  K_RSHIFT = 229,
  K_RALT = 230,
  K_RGUI = 231,
  K_MODE = 257,
  K_AUDIONEXT = 258,
  K_AUDIOPREV = 259,
  K_AUDIOSTOP = 260,
  K_AUDIOPLAY = 261,
  K_AUDIOMUTE = 262,
  K_MEDIASELECT = 263,
  K_WWW = 264,
  K_MAIL = 265,
  K_CALCULATOR = 266,
  K_COMPUTER = 267,
  K_AC_SEARCH = 268,
  K_AC_HOME = 269,
  K_AC_BACK = 270,
  K_AC_FORWARD = 271,
  K_AC_STOP = 272,
  K_AC_REFRESH = 273,
  K_AC_BOOKMARKS = 274,
  K_BRIGHTNESSDOWN = 275,
  K_BRIGHTNESSUP = 276,
  K_DISPLAYSWITCH = 277,
  K_KBDILLUMTOGGLE = 278,
  K_KBDILLUMDOWN = 279,
  K_KBDILLUMUP = 280,
  K_EJECT = 281,
  K_SLEEP = 282,
  
  C_MOVEU = 283,
  C_MOVER = 284,
  C_MOVED = 285,
  C_MOVEL = 286,
  C_MOVEX = 287,
  C_MOVEY = 288,
  C_LOOKU = 289,
  C_LOOKR = 290,
  C_LOOKD = 291,
  C_LOOKL = 292,
  C_LOOKX = 293,
  C_LOOKY = 294,
  C_A = 295,
  C_B = 296,
  C_X = 297,
  C_Y = 298,
  C_LB = 299,
  C_RB = 300,
  C_LT = 301,
  C_RT = 302,
  C_LS = 303,
  C_RS = 304,
  C_U = 305,
  C_R = 306,
  C_D = 307,
  C_L = 308,
  C_BACK = 309,
  C_START = 310,
  C_GUIDE = 311,
  C_BIGASS = 312,
  
  I_END
};


std::string Input_Name(Input_Enum i)
{
  switch (i)
  {
    case 4: return "K_A"; break;
    case 5: return "K_B"; break;
    case 6: return "K_C"; break;
    case 7: return "K_D"; break;
    case 8: return "K_E"; break;
    case 9: return "K_F"; break;
    case 10: return "K_G"; break;
    case 11: return "K_H"; break;
    case 12: return "K_I"; break;
    case 13: return "K_J"; break;
    case 14: return "K_K"; break;
    case 15: return "K_L"; break;
    case 16: return "K_M"; break;
    case 17: return "K_N"; break;
    case 18: return "K_O"; break;
    case 19: return "K_P"; break;
    case 20: return "K_Q"; break;
    case 21: return "K_R"; break;
    case 22: return "K_S"; break;
    case 23: return "K_T"; break;
    case 24: return "K_U"; break;
    case 25: return "K_V"; break;
    case 26: return "K_W"; break;
    case 27: return "K_X"; break;
    case 28: return "K_Y"; break;
    case 29: return "K_Z"; break;
    case 30: return "K_1"; break;
    case 31: return "K_2"; break;
    case 32: return "K_3"; break;
    case 33: return "K_4"; break;
    case 34: return "K_5"; break;
    case 35: return "K_6"; break;
    case 36: return "K_7"; break;
    case 37: return "K_8"; break;
    case 38: return "K_9"; break;
    case 39: return "K_0"; break;
    case 40: return "K_RETURN"; break;
    case 41: return "K_ESCAPE"; break;
    case 42: return "K_BACKSPACE"; break;
    case 43: return "K_TAB"; break;
    case 44: return "K_SPACE"; break;
    case 45: return "K_MINUS"; break;
    case 46: return "K_EQUALS"; break;
    case 47: return "K_LEFTBRACKET"; break;
    case 48: return "K_RIGHTBRACKET"; break;
    case 49: return "K_BACKSLASH"; break;
    case 51: return "K_SEMICOLON"; break;
    case 52: return "K_APOSTROPHE"; break;
    case 53: return "K_GRAVE"; break;
    case 54: return "K_COMMA"; break;
    case 55: return "K_PERIOD"; break;
    case 56: return "K_SLASH"; break;
    case 57: return "K_CAPSLOCK"; break;
    case 58: return "K_F1"; break;
    case 59: return "K_F2"; break;
    case 60: return "K_F3"; break;
    case 61: return "K_F4"; break;
    case 62: return "K_F5"; break;
    case 63: return "K_F6"; break;
    case 64: return "K_F7"; break;
    case 65: return "K_F8"; break;
    case 66: return "K_F9"; break;
    case 67: return "K_F10"; break;
    case 68: return "K_F11"; break;
    case 69: return "K_F12"; break;
    case 70: return "K_PRINTSCREEN"; break;
    case 71: return "K_SCROLLLOCK"; break;
    case 72: return "K_PAUSE"; break;
    case 73: return "K_INSERT"; break;
    case 74: return "K_HOME"; break;
    case 75: return "K_PAGEUP"; break;
    case 76: return "K_DELETE"; break;
    case 77: return "K_END"; break;
    case 78: return "K_PAGEDOWN"; break;
    case 79: return "K_RIGHT"; break;
    case 80: return "K_LEFT"; break;
    case 81: return "K_DOWN"; break;
    case 82: return "K_UP"; break;
    case 83: return "K_NUMLOCKCLEAR"; break;
    case 84: return "K_KP_DIVIDE"; break;
    case 85: return "K_KP_MULTIPLY"; break;
    case 86: return "K_KP_MINUS"; break;
    case 87: return "K_KP_PLUS"; break;
    case 88: return "K_KP_ENTER"; break;
    case 89: return "K_KP_1"; break;
    case 90: return "K_KP_2"; break;
    case 91: return "K_KP_3"; break;
    case 92: return "K_KP_4"; break;
    case 93: return "K_KP_5"; break;
    case 94: return "K_KP_6"; break;
    case 95: return "K_KP_7"; break;
    case 96: return "K_KP_8"; break;
    case 97: return "K_KP_9"; break;
    case 98: return "K_KP_0"; break;
    case 99: return "K_KP_PERIOD"; break;
    case 101: return "K_APPLICATION"; break;
    case 102: return "K_POWER"; break;
    case 103: return "K_KP_EQUALS"; break;
    case 104: return "K_F13"; break;
    case 105: return "K_F14"; break;
    case 106: return "K_F15"; break;
    case 107: return "K_F16"; break;
    case 108: return "K_F17"; break;
    case 109: return "K_F18"; break;
    case 110: return "K_F19"; break;
    case 111: return "K_F20"; break;
    case 112: return "K_F21"; break;
    case 113: return "K_F22"; break;
    case 114: return "K_F23"; break;
    case 115: return "K_F24"; break;
    case 116: return "K_EXECUTE"; break;
    case 117: return "K_HELP"; break;
    case 118: return "K_MENU"; break;
    case 119: return "K_SELECT"; break;
    case 120: return "K_STOP"; break;
    case 121: return "K_AGAIN"; break;
    case 122: return "K_UNDO"; break;
    case 123: return "K_CUT"; break;
    case 124: return "K_COPY"; break;
    case 125: return "K_PASTE"; break;
    case 126: return "K_FIND"; break;
    case 127: return "K_MUTE"; break;
    case 128: return "K_VOLUMEUP"; break;
    case 129: return "K_VOLUMEDOWN"; break;
    case 133: return "K_KP_COMMA"; break;
    case 134: return "K_KP_EQUALSAS400"; break;
    case 153: return "K_ALTERASE"; break;
    case 154: return "K_SYSREQ"; break;
    case 155: return "K_CANCEL"; break;
    case 156: return "K_CLEAR"; break;
    case 157: return "K_PRIOR"; break;
    case 158: return "K_RETURN2"; break;
    case 159: return "K_SEPARATOR"; break;
    case 160: return "K_OUT"; break;
    case 161: return "K_OPER"; break;
    case 162: return "K_CLEARAGAIN"; break;
    case 163: return "K_CRSEL"; break;
    case 164: return "K_EXSEL"; break;
    case 176: return "K_KP_00"; break;
    case 177: return "K_KP_000"; break;
    case 178: return "K_THOUSANDSSEPARATOR"; break;
    case 179: return "K_DECIMALSEPARATOR"; break;
    case 180: return "K_CURRENCYUNIT"; break;
    case 181: return "K_CURRENCYSUBUNIT"; break;
    case 182: return "K_KP_LEFTPAREN"; break;
    case 183: return "K_KP_RIGHTPAREN"; break;
    case 184: return "K_KP_LEFTBRACE"; break;
    case 185: return "K_KP_RIGHTBRACE"; break;
    case 186: return "K_KP_TAB"; break;
    case 187: return "K_KP_BACKSPACE"; break;
    case 188: return "K_KP_A"; break;
    case 189: return "K_KP_B"; break;
    case 190: return "K_KP_C"; break;
    case 191: return "K_KP_D"; break;
    case 192: return "K_KP_E"; break;
    case 193: return "K_KP_F"; break;
    case 194: return "K_KP_XOR"; break;
    case 195: return "K_KP_POWER"; break;
    case 196: return "K_KP_PERCENT"; break;
    case 197: return "K_KP_LESS"; break;
    case 198: return "K_KP_GREATER"; break;
    case 199: return "K_KP_AMPERSAND"; break;
    case 200: return "K_KP_DBLAMPERSAND"; break;
    case 201: return "K_KP_VERTICALBAR"; break;
    case 202: return "K_KP_DBLVERTICALBAR"; break;
    case 203: return "K_KP_COLON"; break;
    case 204: return "K_KP_HASH"; break;
    case 205: return "K_KP_SPACE"; break;
    case 206: return "K_KP_AT"; break;
    case 207: return "K_KP_EXCLAM"; break;
    case 208: return "K_KP_MEMSTORE"; break;
    case 209: return "K_KP_MEMRECALL"; break;
    case 210: return "K_KP_MEMCLEAR"; break;
    case 211: return "K_KP_MEMADD"; break;
    case 212: return "K_KP_MEMSUBTRACT"; break;
    case 213: return "K_KP_MEMMULTIPLY"; break;
    case 214: return "K_KP_MEMDIVIDE"; break;
    case 215: return "K_KP_PLUSMINUS"; break;
    case 216: return "K_KP_CLEAR"; break;
    case 217: return "K_KP_CLEARENTRY"; break;
    case 218: return "K_KP_BINARY"; break;
    case 219: return "K_KP_OCTAL"; break;
    case 220: return "K_KP_DECIMAL"; break;
    case 221: return "K_KP_HEXADECIMAL"; break;
    case 224: return "K_LCTRL"; break;
    case 225: return "K_LSHIFT"; break;
    case 226: return "K_LALT"; break;
    case 227: return "K_LGUI"; break;
    case 228: return "K_RCTRL"; break;
    case 229: return "K_RSHIFT"; break;
    case 230: return "K_RALT"; break;
    case 231: return "K_RGUI"; break;
    case 257: return "K_MODE"; break;
    case 258: return "K_AUDIONEXT"; break;
    case 259: return "K_AUDIOPREV"; break;
    case 260: return "K_AUDIOSTOP"; break;
    case 261: return "K_AUDIOPLAY"; break;
    case 262: return "K_AUDIOMUTE"; break;
    case 263: return "K_MEDIASELECT"; break;
    case 264: return "K_WWW"; break;
    case 265: return "K_MAIL"; break;
    case 266: return "K_CALCULATOR"; break;
    case 267: return "K_COMPUTER"; break;
    case 268: return "K_AC_SEARCH"; break;
    case 269: return "K_AC_HOME"; break;
    case 270: return "K_AC_BACK"; break;
    case 271: return "K_AC_FORWARD"; break;
    case 272: return "K_AC_STOP"; break;
    case 273: return "K_AC_REFRESH"; break;
    case 274: return "K_AC_BOOKMARKS"; break;
    case 275: return "K_BRIGHTNESSDOWN"; break;
    case 276: return "K_BRIGHTNESSUP"; break;
    case 277: return "K_DISPLAYSWITCH"; break;
    case 278: return "K_KBDILLUMTOGGLE"; break;
    case 279: return "K_KBDILLUMDOWN"; break;
    case 280: return "K_KBDILLUMUP"; break;
    case 281: return "K_EJECT"; break;
    case 282: return "K_SLEEP"; break;

    case 283: return "C_MOVEU"; break;
    case 284: return "C_MOVER"; break;
    case 285: return "C_MOVED"; break;
    case 286: return "C_MOVEL"; break;
    case 287: return "C_MOVEX"; break;
    case 288: return "C_MOVEY"; break;
    case 289: return "C_LOOKU"; break;
    case 290: return "C_LOOKR"; break;
    case 291: return "C_LOOKD"; break;
    case 292: return "C_LOOKL"; break;
    case 293: return "C_LOOKX"; break;
    case 294: return "C_LOOKY"; break;
    case 295: return "C_A"; break;
    case 296: return "C_B"; break;
    case 297: return "C_X"; break;
    case 298: return "C_Y"; break;
    case 299: return "C_LB"; break;
    case 300: return "C_RB"; break;
    case 301: return "C_LT"; break;
    case 302: return "C_RT"; break;
    case 303: return "C_LS"; break;
    case 304: return "C_RS"; break;
    case 305: return "C_U"; break;
    case 306: return "C_R"; break;
    case 307: return "C_D"; break;
    case 308: return "C_L"; break;
    case 309: return "C_BACK"; break;
    case 310: return "C_START"; break;
    case 311: return "C_GUIDE"; break;
    case 312: return "C_BIGASS"; break;
    default: return "UNKNOWN"; break;
  }
}
