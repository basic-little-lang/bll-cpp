#include <string>
#include <vector>
#include <iostream>
#include "include/args.hpp"


args::Result* args::build(const std::vector<std::string>& args) {

    Result* result = new Result;

    if (args.size() < 2) {
        result->success = false;
        result->data = nullptr;
        return result;
    }

    result->success = true;

    Args* args_obj = new Args(args[1]);

    result->data = args_obj;

    return result;

}

std::string args::Args::get_file_name() const {
    return this->file_name;
}
