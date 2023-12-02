#include "include/color.hpp"

unsigned short color::code_for_color(color::Color &color) {

    switch (color) {
        case Color::FOREGROUND_BLACK:
            return 30;
        case Color::FOREGROUND_RED:
            return 31;
        case Color::FOREGROUND_GREEN:
            return 32;
        case Color::FOREGROUND_YELLOW:
            return 33;
        case Color::FOREGROUND_BLUE:
            return 34;
        case Color::FOREGROUND_MAGENTA:
            return 35;
        case Color::FOREGROUND_CYAN:
            return 36;
        case Color::FOREGROUND_WHITE:
            return 37;
        case Color::FOREGROUND_LIGHT_BLACK:
            return 90;
        case Color::FOREGROUND_LIGHT_RED:
            return 91;
        case Color::FOREGROUND_LIGHT_GREEN:
            return 92;
        case Color::FOREGROUND_LIGHT_YELLOW:
            return 93;
        case Color::FOREGROUND_LIGHT_BLUE:
            return 94;
        case Color::FOREGROUND_LIGHT_MAGENTA:
            return 95;
        case Color::FOREGROUND_LIGHT_CYAN:
            return 96;
        case Color::FOREGROUND_LIGHT_WHITE:
            return 97;

        case Color::BACKGROUND_BLACK:
            return 40;
        case Color::BACKGROUND_RED:
            return 41;
        case Color::BACKGROUND_GREEN:
            return 42;
        case Color::BACKGROUND_YELLOW:
            return 43;
        case Color::BACKGROUND_BLUE:
            return 44;
        case Color::BACKGROUND_MAGENTA:
            return 45;
        case Color::BACKGROUND_CYAN:
            return 46;
        case Color::BACKGROUND_WHITE:
            return 47;
        case Color::BACKGROUND_LIGHT_BLACK:
            return 100;
        case Color::BACKGROUND_LIGHT_RED:
            return 101;
        case Color::BACKGROUND_LIGHT_GREEN:
            return 102;
        case Color::BACKGROUND_LIGHT_YELLOW:
            return 103;
        case Color::BACKGROUND_LIGHT_BLUE:
            return 104;
        case Color::BACKGROUND_LIGHT_MAGENTA:
            return 105;
        case Color::BACKGROUND_LIGHT_CYAN:
            return 106;
        case Color::BACKGROUND_LIGHT_WHITE:
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
