
#ifndef _ARGS_HPP_
#define _ARGS_HPP_

#include <string>
#include <vector>

namespace args {

    class Args {
        private:
            std::string file_name;
        public:
            Args(std::string file_name) : file_name(file_name) {}
            std::string get_file_name() const;
    };

    struct Result {
        bool success;
        Args* data;
    };

    Result* build(const std::vector<std::string>& args);

}

#endif
