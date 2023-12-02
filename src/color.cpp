#include "include/color.hpp"

std::string color::color_to_string(color::Color color) {
    unsigned short code = color::code_for_color(color);
    bool is_foreground = color::is_foreground(color);

    std::string str;

    if (is_foreground) {
        str = "\033[" + std::to_string(code) + "m";
    } else {
        str = "\033[;" + std::to_string(code) + "m";
    }

    return str;
}

bool color::is_foreground(color::Color color) {
    unsigned short code = color::code_for_color(color);

    return (code >= 30 && code <= 97);
}

unsigned short color::code_for_color(color::Color color) {

    switch (color) {
        case color::Color::FOREGROUND_BLACK:
            return 30;
        case color::Color::FOREGROUND_RED:
            return 31;
        case color::Color::FOREGROUND_GREEN:
            return 32;
        case color::Color::FOREGROUND_YELLOW:
            return 33;
        case color::Color::FOREGROUND_BLUE:
            return 34;
        case color::Color::FOREGROUND_MAGENTA:
            return 35;
        case color::Color::FOREGROUND_CYAN:
            return 36;
        case color::Color::FOREGROUND_WHITE:
            return 37;
        case color::Color::FOREGROUND_LIGHT_BLACK:
            return 90;
        case color::Color::FOREGROUND_LIGHT_RED:
            return 91;
        case color::Color::FOREGROUND_LIGHT_GREEN:
            return 92;
        case color::Color::FOREGROUND_LIGHT_YELLOW:
            return 93;
        case color::Color::FOREGROUND_LIGHT_BLUE:
            return 94;
        case color::Color::FOREGROUND_LIGHT_MAGENTA:
            return 95;
        case color::Color::FOREGROUND_LIGHT_CYAN:
            return 96;
        case color::Color::FOREGROUND_LIGHT_WHITE:
            return 97;

        case color::Color::BACKGROUND_BLACK:
            return 40;
        case color::Color::BACKGROUND_RED:
            return 41;
        case color::Color::BACKGROUND_GREEN:
            return 42;
        case color::Color::BACKGROUND_YELLOW:
            return 43;
        case color::Color::BACKGROUND_BLUE:
            return 44;
        case color::Color::BACKGROUND_MAGENTA:
            return 45;
        case color::Color::BACKGROUND_CYAN:
            return 46;
        case color::Color::BACKGROUND_WHITE:
            return 47;
        case color::Color::BACKGROUND_LIGHT_BLACK:
            return 100;
        case color::Color::BACKGROUND_LIGHT_RED:
            return 101;
        case color::Color::BACKGROUND_LIGHT_GREEN:
            return 102;
        case color::Color::BACKGROUND_LIGHT_YELLOW:
            return 103;
        case color::Color::BACKGROUND_LIGHT_BLUE:
            return 104;
        case color::Color::BACKGROUND_LIGHT_MAGENTA:
            return 105;
        case color::Color::BACKGROUND_LIGHT_CYAN:
            return 106;
        case color::Color::BACKGROUND_LIGHT_WHITE:
            return 107;

        
        case Color::RESET:
            return 0;
        case Color::BOLD:
            return 1;
        case Color::ITALIC:
            return 3;
        case Color::UNDERLINE:
            return 4;
    }

}
