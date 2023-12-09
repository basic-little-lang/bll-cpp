#include "include/tokens.hpp"
#include <vector>
#include <string>

const char parser::tokens::COMMENT_CHAR = '#';

parser::tokens::TokenType parser::tokens::Token::get_token_type() const {
    return this->token_type;
}

char parser::tokens::TokenChar::get_data() const {
    return this->data;
}

std::string parser::tokens::TokenChar::string() const {
    std::string str("CHAR(");
    str.push_back(this->get_data());
    str.push_back(')');
    return str;
}

std::string parser::tokens::TokenBase::string() const {
    switch (this->get_token_type()) {
        case parser::tokens::TokenType::ADD:
            return "ADD";
        case parser::tokens::TokenType::SUBTRACT:
            return "SUBTRACT";
        case parser::tokens::TokenType::DIVIDE:
            return "DIVIDE";
        case parser::tokens::TokenType::MULTIPLIE:
            return "MULTIPLIE";
        case parser::tokens::TokenType::MODULO:
            return "MODULO";
        case parser::tokens::TokenType::POWER:
            return "POWER";
        case parser::tokens::TokenType::EQUAL:
            return "EQUAL";
        case parser::tokens::TokenType::NEGITIVE:
            return "NEGITIVE";
        case parser::tokens::TokenType::POINT:
            return "POINT";
        case parser::tokens::TokenType::WHITESPACE:
            return "WHITESPACE";
        default:
            return "";
    }
}

std::vector<parser::tokens::Token*>* parser::tokens::tokenize_string(std::string *str) {
    std::vector<parser::tokens::Token*>* tokens = new std::vector<parser::tokens::Token*>;

    bool skip_comment = false;
    bool free_if_fail = false;

    for (int i = 0; i < str->length(); i++) {
        char chr = str->at(i);

        if (chr == '\n') {
            if (skip_comment) {
                skip_comment = false;
                continue;
            }
            tokens->push_back(new parser::tokens::TokenBase(parser::tokens::TokenType::WHITESPACE));
            free_if_fail = true;
            continue;
        }
        if (skip_comment) continue;
        if (chr == parser::tokens::COMMENT_CHAR) {
            skip_comment = true;
            continue;
        }
        if (std::isspace(chr)) {
            tokens->push_back(new parser::tokens::TokenBase(parser::tokens::TokenType::WHITESPACE));
            free_if_fail = true;
            continue;
        }
        
        switch (chr) {
            case '+':
                tokens->push_back(new parser::tokens::TokenBase(parser::tokens::TokenType::ADD));
                free_if_fail = true;
                break;
            case '-':
                {
                    int next_index = i + 1;
                    if (next_index > str->length() && next_index > 0) {
                        if (free_if_fail) {
                            for (int j = 0; j < tokens->size(); j++) {
                                delete tokens->at(j);
                            }
                        }
                        delete tokens;
                        return nullptr;
                    }

                    char ch = str->at(next_index);

                    if (std::isspace(ch)) {
                        tokens->push_back(new parser::tokens::TokenBase(parser::tokens::TokenType::SUBTRACT));
                    } else {
                        tokens->push_back(new parser::tokens::TokenBase(parser::tokens::TokenType::NEGITIVE));
                    }
                    free_if_fail = true;
                }
                break;
            case '*':
                tokens->push_back(new parser::tokens::TokenBase(parser::tokens::TokenType::MULTIPLIE));
                free_if_fail = true;
                break;
            case '/':
                tokens->push_back(new parser::tokens::TokenBase(parser::tokens::TokenType::DIVIDE));
                free_if_fail = true;
                break;
            case '%':
                tokens->push_back(new parser::tokens::TokenBase(parser::tokens::TokenType::MODULO));
                free_if_fail = true;
                break;
            case '^':
                tokens->push_back(new parser::tokens::TokenBase(parser::tokens::TokenType::POWER));
                free_if_fail = true;
                break;
            case '.':
                tokens->push_back(new parser::tokens::TokenBase(parser::tokens::TokenType::POINT));
                free_if_fail = true;
                break;
            case '=':
                tokens->push_back(new parser::tokens::TokenBase(parser::tokens::TokenType::EQUAL));
                free_if_fail = true;
                break;
            default:
                if (!std::isdigit(chr) && !std::isalpha(chr)) {
                    continue;
                }
                tokens->push_back(new parser::tokens::TokenChar(chr));
                free_if_fail = true;
                break;
        }


    }

    return tokens;
}
