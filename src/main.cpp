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

    return 0;
}
