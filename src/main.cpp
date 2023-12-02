#include <iostream>
#include "include/args.hpp"
#include "include/color.hpp"
#include "include/filereader.hpp"


int main(int argc, char const *argv[]) {

    int exit_code = 0;

    std::vector<std::string> args_vec(argv, argv + argc);

    args::Result* args_result = args::build(args_vec);
    if (!args_result->success) {
        std::cout << color::format_color(color::format_color("error", color::Color::FOREGROUND_LIGHT_RED), color::Color::BOLD) << ": Cannot parse args" << std::endl;
        exit_code = 1;
        return exit_code;
    }

    std::string* contents = filereader::read_file_to_string(args_result->data->get_file_name());
    if (contents == nullptr) {
        std::cout << color::format_color(color::format_color("error", color::Color::FOREGROUND_LIGHT_RED), color::Color::BOLD) << ": Cannot open file: " << args_result->data->get_file_name() << std::endl;
        exit_code = 1;
        goto exit_file;
    }

    std::cout << *contents << '\n';

    delete contents;

    exit_file:
        delete args_result->data;
        delete args_result;

        return exit_code;
}
