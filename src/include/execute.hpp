
#ifndef _EXECUTE_HPP_
#define _EXECUTE_HPP_

#include <vector>
#include "parser.hpp"

namespace execute {

    bool execute(std::vector<parser::ParsedToken*>* tokens);

}

#endif
