#include "Key.h"

#include "Library/Serialization/EnumSerialization.h"

// TODO(captainurist): recheck that ALL keys are actually serializable
MM_DEFINE_ENUM_SERIALIZATION_FUNCTIONS(PlatformKey, CASE_INSENSITIVE, {
    {PlatformKey::F1,           "F1" },
    {PlatformKey::F2,           "F2" },
    {PlatformKey::F3,           "F3" },
    {PlatformKey::F4,           "F4" },
    {PlatformKey::F5,           "F5" },
    {PlatformKey::F6,           "F6" },
    {PlatformKey::F7,           "F7" },
    {PlatformKey::F8,           "F8" },
    {PlatformKey::F9,           "F9" },
    {PlatformKey::F10,          "F10" },
    {PlatformKey::F11,          "F11" },
    {PlatformKey::F12,          "F12" },

    {PlatformKey::A,            "A" },
    {PlatformKey::B,            "B" },
    {PlatformKey::C,            "C" },
    {PlatformKey::D,            "D" },
    {PlatformKey::E,            "E" },
    {PlatformKey::F,            "F" },
    {PlatformKey::G,            "G" },
    {PlatformKey::H,            "H" },
    {PlatformKey::I,            "I" },
    {PlatformKey::J,            "J" },
    {PlatformKey::K,            "K" },
    {PlatformKey::L,            "L" },
    {PlatformKey::M,            "M" },
    {PlatformKey::N,            "N" },
    {PlatformKey::O,            "O" },
    {PlatformKey::P,            "P" },
    {PlatformKey::Q,            "Q" },
    {PlatformKey::R,            "R" },
    {PlatformKey::S,            "S" },
    {PlatformKey::T,            "T" },
    {PlatformKey::U,            "U" },
    {PlatformKey::V,            "V" },
    {PlatformKey::W,            "W" },
    {PlatformKey::X,            "X" },
    {PlatformKey::Y,            "Y" },
    {PlatformKey::Z,            "Z" },

    {PlatformKey::Digit1,       "1" },
    {PlatformKey::Digit2,       "2" },
    {PlatformKey::Digit3,       "3" },
    {PlatformKey::Digit4,       "4" },
    {PlatformKey::Digit5,       "5" },
    {PlatformKey::Digit6,       "6" },
    {PlatformKey::Digit7,       "7" },
    {PlatformKey::Digit8,       "8" },
    {PlatformKey::Digit9,       "9" },
    {PlatformKey::Digit0,       "0" },

    {PlatformKey::Up,           "UP" },
    {PlatformKey::Down,         "DOWN" },
    {PlatformKey::Left,         "LEFT" },
    {PlatformKey::Right,        "RIGHT" },
    {PlatformKey::Return,       "RETURN" },
    {PlatformKey::Escape,       "ESCAPE" },
    {PlatformKey::Space,        "SPACE" },
    {PlatformKey::PageDown,     "PAGE DOWN" },
    {PlatformKey::PageUp,       "PAGE UP" },
    {PlatformKey::Tab,          "TAB" },
    {PlatformKey::Subtract,     "SUBTRACT" },
    {PlatformKey::Add,          "ADD" },
    {PlatformKey::End,          "END" },
    {PlatformKey::Delete,       "DELETE" },
    {PlatformKey::Home,         "HOME" },
    {PlatformKey::Insert,       "INSERT" },
    {PlatformKey::Comma,        "COMMA" },
    {PlatformKey::Decimal,      "DECIMAL" },
    {PlatformKey::Semicolon,    "SEMICOLON" },
    {PlatformKey::Period,       "PERIOD" },
    {PlatformKey::Slash,        "SLASH" },
    {PlatformKey::SingleQuote,  "SQUOTE" },
    {PlatformKey::BackSlash,    "BACKSLASH" },
    {PlatformKey::Backspace,    "BACKSPACE" },
    {PlatformKey::LeftBracket,  "L BRACKET" },
    {PlatformKey::RightBracket, "R BRACKET" },
    {PlatformKey::Tilde,        "~" },

    {PlatformKey::Control,      "CONTROL"},
    {PlatformKey::Alt,          "ALT"},
    {PlatformKey::Shift,        "SHIFT"},

    {PlatformKey::Numpad0,      "NUMPAD 0" },
    {PlatformKey::Numpad1,      "NUMPAD 1" },
    {PlatformKey::Numpad2,      "NUMPAD 2" },
    {PlatformKey::Numpad3,      "NUMPAD 3" },
    {PlatformKey::Numpad4,      "NUMPAD 4" },
    {PlatformKey::Numpad5,      "NUMPAD 5" },
    {PlatformKey::Numpad6,      "NUMPAD 6" },
    {PlatformKey::Numpad7,      "NUMPAD 7" },
    {PlatformKey::Numpad8,      "NUMPAD 8" },
    {PlatformKey::Numpad9,      "NUMPAD 9" },

    {PlatformKey::Gamepad_A,        "A (CROSS)"},
    {PlatformKey::Gamepad_B,        "B (CIRCLE)"},
    {PlatformKey::Gamepad_X,        "X (SQUARE)"},
    {PlatformKey::Gamepad_Y,        "Y (TRIANGLE)"},
    {PlatformKey::Gamepad_Left,     "DPAD LEFT"},
    {PlatformKey::Gamepad_Right,    "DPAD RIGHT"},
    {PlatformKey::Gamepad_Up,       "DPAD UP"},
    {PlatformKey::Gamepad_Down,     "DPAD DOWN"},
    {PlatformKey::Gamepad_L1,       "L1"},
    {PlatformKey::Gamepad_R1,       "R1"},
    {PlatformKey::Gamepad_L3,       "L3"},
    {PlatformKey::Gamepad_R3,       "R3"},
    {PlatformKey::Gamepad_Start,    "START"},
    {PlatformKey::Gamepad_Back,     "BACK"},
    {PlatformKey::Gamepad_Guide,    "GUIDE"},
    {PlatformKey::Gamepad_Touchpad, "TOUCHPAD"},

    {PlatformKey::Gamepad_LeftStick_Left,   "LSTICK LEFT"},
    {PlatformKey::Gamepad_LeftStick_Right,  "LSTICK RIGHT"},
    {PlatformKey::Gamepad_LeftStick_Up,     "LSTICK UP"},
    {PlatformKey::Gamepad_LeftStick_Down,   "LSTICK DOWN"},
    {PlatformKey::Gamepad_RightStick_Left,  "RSTICK LEFT"},
    {PlatformKey::Gamepad_RightStick_Right, "RSTICK RIGHT"},
    {PlatformKey::Gamepad_RightStick_Up,    "RSTICK UP"},
    {PlatformKey::Gamepad_RightStick_Down,  "RSTICK DOWN"},
    {PlatformKey::Gamepad_L2,               "L2"},
    {PlatformKey::Gamepad_R2,               "R2"},
    {PlatformKey::None,                     "-NOT-SET-"}
})

std::string GetDisplayName(PlatformKey key) {
    return toString(key); // Should always work.
}

bool TryParseDisplayName(std::string_view displayName, PlatformKey *outKey) {
    return tryDeserialize(displayName, outKey);
}
