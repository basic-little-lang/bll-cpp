#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <cmath>
#include <iomanip>
#include "include/parser.hpp"
#include "include/execute.hpp"

bool execute::execute(std::vector<parser::ParsedToken*> *tokens) {
    std::map<std::string, double>* vars = new std::map<std::string, double>;
    double last_val = 0;

    for (unsigned long int i = 0; i < tokens->size(); i++) {
        parser::ParsedToken* token = tokens->at(i);

        parser::ParsedToken* last_token;
        parser::ParsedToken* next_token;

        unsigned long int last_index = i - 1;
        unsigned long int next_index = i + 1;

        if (last_index < 0) {
            last_token = nullptr;
        } else {
            last_token = tokens->at(last_index);
        }

        if (!(next_index < tokens->size())) {
            next_token = nullptr;
        } else {
            next_token = tokens->at(next_index);
        }

        switch (token->get_token_type()) {
            case parser::ParsedTokenType::ADD:
                {
                    if (last_token == nullptr || next_token == nullptr) {
                        delete vars;
                        return false;
                    }

                    double last_v;
                    double next_v;

                    switch (last_token->get_token_type()) {
                        case parser::ParsedTokenType::NUMBER:
                            last_v = ((parser::NumberParsedToken*) last_token)->get_number();
                            break;
                        case parser::ParsedTokenType::VAR:
                            last_v = (*vars)[((parser::VarParsedToken*) last_token)->get_name()];
                            break;
                        default:
                            delete vars;
                            return false;
                    }

                    switch (next_token->get_token_type()) {
                        case parser::ParsedTokenType::NUMBER:
                            next_v = ((parser::NumberParsedToken*) next_token)->get_number();
                            break;
                        case parser::ParsedTokenType::VAR:
                            next_v = (*vars)[((parser::VarParsedToken*) next_token)->get_name()];
                            break;
                        default:
                            delete vars;
                            return false;
                    }

                    last_val = last_v + next_v;

                }
                break;
            case parser::ParsedTokenType::SUBTRACT:
                {
                    if (last_token == nullptr || next_token == nullptr) {
                        delete vars;
                        return false;
                    }

                    double last_v;
                    double next_v;

                    switch (last_token->get_token_type()) {
                        case parser::ParsedTokenType::NUMBER:
                            last_v = ((parser::NumberParsedToken*) last_token)->get_number();
                            break;
                        case parser::ParsedTokenType::VAR:
                            last_v = (*vars)[((parser::VarParsedToken*) last_token)->get_name()];
                            break;
                        default:
                            delete vars;
                            return false;
                    }

                    switch (next_token->get_token_type()) {
                        case parser::ParsedTokenType::NUMBER:
                            next_v = ((parser::NumberParsedToken*) next_token)->get_number();
                            break;
                        case parser::ParsedTokenType::VAR:
                            next_v = (*vars)[((parser::VarParsedToken*) next_token)->get_name()];
                            break;
                        default:
                            delete vars;
                            return false;
                    }

                    last_val = last_v - next_v;

                }
                break;
            case parser::ParsedTokenType::MULTIPLIE:
                {
                    if (last_token == nullptr || next_token == nullptr) {
                        delete vars;
                        return false;
                    }

                    double last_v;
                    double next_v;

                    switch (last_token->get_token_type()) {
                        case parser::ParsedTokenType::NUMBER:
                            last_v = ((parser::NumberParsedToken*) last_token)->get_number();
                            break;
                        case parser::ParsedTokenType::VAR:
                            last_v = (*vars)[((parser::VarParsedToken*) last_token)->get_name()];
                            break;
                        default:
                            delete vars;
                            return false;
                    }

                    switch (next_token->get_token_type()) {
                        case parser::ParsedTokenType::NUMBER:
                            next_v = ((parser::NumberParsedToken*) next_token)->get_number();
                            break;
                        case parser::ParsedTokenType::VAR:
                            next_v = (*vars)[((parser::VarParsedToken*) next_token)->get_name()];
                            break;
                        default:
                            delete vars;
                            return false;
                    }

                    last_val = last_v * next_v;

                }
                break;
            case parser::ParsedTokenType::DIVIDE:
                {
                    if (last_token == nullptr || next_token == nullptr) {
                        delete vars;
                        return false;
                    }

                    double last_v;
                    double next_v;

                    switch (last_token->get_token_type()) {
                        case parser::ParsedTokenType::NUMBER:
                            last_v = ((parser::NumberParsedToken*) last_token)->get_number();
                            break;
                        case parser::ParsedTokenType::VAR:
                            last_v = (*vars)[((parser::VarParsedToken*) last_token)->get_name()];
                            break;
                        default:
                            delete vars;
                            return false;
                    }

                    switch (next_token->get_token_type()) {
                        case parser::ParsedTokenType::NUMBER:
                            next_v = ((parser::NumberParsedToken*) next_token)->get_number();
                            break;
                        case parser::ParsedTokenType::VAR:
                            next_v = (*vars)[((parser::VarParsedToken*) next_token)->get_name()];
                            break;
                        default:
                            delete vars;
                            return false;
                    }

                    last_val = last_v / next_v;

                }
                break;
            case parser::ParsedTokenType::MODULO:
                {
                    if (last_token == nullptr || next_token == nullptr) {
                        delete vars;
                        return false;
                    }

                    double last_v;
                    double next_v;

                    switch (last_token->get_token_type()) {
                        case parser::ParsedTokenType::NUMBER:
                            last_v = ((parser::NumberParsedToken*) last_token)->get_number();
                            break;
                        case parser::ParsedTokenType::VAR:
                            last_v = (*vars)[((parser::VarParsedToken*) last_token)->get_name()];
                            break;
                        default:
                            delete vars;
                            return false;
                    }

                    switch (next_token->get_token_type()) {
                        case parser::ParsedTokenType::NUMBER:
                            next_v = ((parser::NumberParsedToken*) next_token)->get_number();
                            break;
                        case parser::ParsedTokenType::VAR:
                            next_v = (*vars)[((parser::VarParsedToken*) next_token)->get_name()];
                            break;
                        default:
                            delete vars;
                            return false;
                    }

                    last_val = (int) last_v % (int) next_v;

                }
                break;
            case parser::ParsedTokenType::POWER:
                {
                    if (last_token == nullptr || next_token == nullptr) {
                        delete vars;
                        return false;
                    }

                    double last_v;
                    double next_v;

                    switch (last_token->get_token_type()) {
                        case parser::ParsedTokenType::NUMBER:
                            last_v = ((parser::NumberParsedToken*) last_token)->get_number();
                            break;
                        case parser::ParsedTokenType::VAR:
                            last_v = (*vars)[((parser::VarParsedToken*) last_token)->get_name()];
                            break;
                        default:
                            delete vars;
                            return false;
                    }

                    switch (next_token->get_token_type()) {
                        case parser::ParsedTokenType::NUMBER:
                            next_v = ((parser::NumberParsedToken*) next_token)->get_number();
                            break;
                        case parser::ParsedTokenType::VAR:
                            next_v = (*vars)[((parser::VarParsedToken*) next_token)->get_name()];
                            break;
                        default:
                            delete vars;
                            return false;
                    }

                    last_val = std::pow(last_v, next_v);

                }
                break;
            case parser::ParsedTokenType::EQUAL:
                {
                    if (last_token == nullptr || next_token == nullptr) {
                        delete vars;
                        return false;
                    }

                    switch (next_token->get_token_type()) {
                        case parser::ParsedTokenType::VAR:
                            (*vars)[((parser::VarParsedToken*) next_token)->get_name()] = last_val;
                            break;
                        case parser::ParsedTokenType::NUMBER:
                            switch (last_token->get_token_type()) {
                                case parser::ParsedTokenType::VAR:
                                    (*vars)[((parser::VarParsedToken*) last_token)->get_name()] = ((parser::NumberParsedToken*) next_token)->get_number();
                                default:
                                    break;
                            }
                            break;
                        default:
                            delete vars;
                            return false;
                    }
                    
                }
                break;
            case parser::ParsedTokenType::PRINT:
                {
                    if (next_token == nullptr) {
                        delete vars;
                        return false;
                    }

                    if (next_token->get_token_type() == parser::ParsedTokenType::VAR) {
                        std::string key = ((parser::VarParsedToken*) next_token)->get_name();
                        std::cout << key << " = " << std::setprecision(16) << vars->at(key) << std::endl;
                    } else {
                        delete vars;
                        return false;
                    }

                }
                break;

            case parser::ParsedTokenType::COPY:
                {
                    if (next_token == nullptr) {
                        delete vars;
                        return false;
                    }

                    unsigned long int next_two_index = i + 2;

                    parser::ParsedToken* next_two_token;

                    if (!(next_two_index < tokens->size())) {
                        next_two_token = nullptr;
                    } else {
                        next_two_token = tokens->at(next_two_index);
                    }

                    if (next_two_token == nullptr) {
                        delete vars;
                        return false;
                    }

                    (*vars)[((parser::VarParsedToken*) next_two_token)->get_name()] = (*vars)[((parser::VarParsedToken*) next_token)->get_name()];
                    
                }
                break;

            default:
                break;
        }

    }

    delete vars;

    return true;
}
