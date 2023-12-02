
#ifndef _COLOR_HPP_
#define _COLOR_HPP_

#include <string>

namespace color {

    enum class Color {
        FOREGROUND_BLACK,
        FOREGROUND_RED,
        FOREGROUND_GREEN,
        FOREGROUND_YELLOW,
        FOREGROUND_BLUE,
        FOREGROUND_MAGENTA,
        FOREGROUND_CYAN,
        FOREGROUND_WHITE,
        FOREGROUND_LIGHT_BLACK,
        FOREGROUND_LIGHT_RED,
        FOREGROUND_LIGHT_GREEN,
        FOREGROUND_LIGHT_YELLOW,
        FOREGROUND_LIGHT_BLUE,
        FOREGROUND_LIGHT_MAGENTA,
        FOREGROUND_LIGHT_CYAN,
        FOREGROUND_LIGHT_WHITE,

        BACKGROUND_BLACK,
        BACKGROUND_RED,
        BACKGROUND_GREEN,
        BACKGROUND_YELLOW,
        BACKGROUND_BLUE,
        BACKGROUND_MAGENTA,
        BACKGROUND_CYAN,
        BACKGROUND_WHITE,
        BACKGROUND_LIGHT_BLACK,
        BACKGROUND_LIGHT_RED,
        BACKGROUND_LIGHT_GREEN,
        BACKGROUND_LIGHT_YELLOW,
        BACKGROUND_LIGHT_BLUE,
        BACKGROUND_LIGHT_MAGENTA,
        BACKGROUND_LIGHT_CYAN,
        BACKGROUND_LIGHT_WHITE,


        RESET,
        BOLD,
        ITALIC,
        UNDERLINE,
    };

    std::string color_to_string(Color color);
    bool is_foreground(Color color);
    unsigned short code_for_color(Color color);

}

#endif
