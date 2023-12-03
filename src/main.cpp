#include <iostream>
#include <vector>
#include <string>
#include "include/args.hpp"
#include "include/color.hpp"
#include "include/execute.hpp"
#include "include/filereader.hpp"
#include "include/parser.hpp"
#include "include/tokens.hpp"


int main(int argc, char const *argv[]) {

    int exit_code = 0;

    std::vector<std::string> args_vec(argv, argv + argc);

    args::Result* args_result = args::build(args_vec);
    if (!args_result->success) {
        std::cout << color::format_color(color::format_color("error", color::Color::FOREGROUND_LIGHT_RED), color::Color::BOLD) << ": Cannot parse args" << std::endl;
        std::cout << color::format_color("usage", color::Color::BOLD) << ": <filename>" << std::endl;
        exit_code = 1;
        return exit_code;
    }

    std::string* contents = filereader::read_file_to_string(args_result->data->get_file_name());
    if (contents == nullptr) {
        std::cout << color::format_color(color::format_color("error", color::Color::FOREGROUND_LIGHT_RED), color::Color::BOLD) << ": Cannot open file: " << args_result->data->get_file_name() << std::endl;
        exit_code = 1;
        goto exit_args;
    }

    std::vector<parser::tokens::Token*>* direct_tokens;
    direct_tokens = parser::tokens::tokenize_string(contents);
    if (direct_tokens == nullptr) {
        std::cout << color::format_color(color::format_color("error", color::Color::FOREGROUND_LIGHT_RED), color::Color::BOLD) << ": Cannot parse file into direct tokens" << std::endl;
        exit_code = 1;
        goto exit_file;
    }

    std::vector<parser::ParsedToken*>* tokens;
    tokens = parser::convert(direct_tokens);
    if (tokens == nullptr) {
        std::cout << color::format_color(color::format_color("error", color::Color::FOREGROUND_LIGHT_RED), color::Color::BOLD) << ": Cannot parse file into tokens" << std::endl;
        exit_code = 1;
        goto exit_direct_tokens;
    }

    bool success;
    success = execute::execute(tokens);
    if (!success) {
        std::cout << color::format_color(color::format_color("error", color::Color::FOREGROUND_LIGHT_RED), color::Color::BOLD) << ": Failed to run code" << std::endl;
        exit_code = 1;
    }

    for (int i = 0; i < tokens->size(); i++) {
        delete tokens->at(i);
    }
    delete tokens;

    exit_direct_tokens:

        for (int i = 0; i < direct_tokens->size(); i++) {
            delete direct_tokens->at(i);
        }
        delete direct_tokens;

    exit_file:

        delete contents;

    exit_args:
    
        delete args_result->data;
        delete args_result;

        return exit_code;
}
