#include <iostream>
#include "include/args.hpp"
#include "include/color.hpp"


int main(int argc, char const *argv[]) {

    std::vector<std::string> args_vec(argv, argv + argc);

    args::Result* args_result = args::build(args_vec);

    if (!args_result->success) {
        
        return 1;
    }


    std::cout << args_result->data->get_file_name() << '\n';

    delete args_result->data;
    delete args_result;

    std::cout << color::color_to_string(color::Color::FOREGROUND_RED) << "hi" << '\n';
    std::cout << color::color_to_string(color::Color::FOREGROUND_BLACK) << color::color_to_string(color::Color::BACKGROUND_CYAN) << "hi" << '\n';

    return 0;
}
