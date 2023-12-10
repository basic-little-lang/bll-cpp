#include <vector>
#include <string>
#include "include/parser.hpp"
#include "include/tokens.hpp"
#include <iostream>

parser::ParsedToken* string_to_keyword(std::string& str) {
    if (str == "print") {
        return new parser::BaseParsedToken(parser::ParsedTokenType::PRINT);
    }
    if (str == "copy") {
        return new parser::BaseParsedToken(parser::ParsedTokenType::COPY);
    }

    return nullptr;
}

std::vector<parser::ParsedToken*>* parser::convert(std::vector<parser::tokens::Token*>* direct_tokens) {
    std::vector<parser::ParsedToken*>* parsered_tokens = new std::vector<parser::ParsedToken*>;
    std::vector<parser::tokens::Token*> buffer;

    for (unsigned long int i = 0; i < direct_tokens->size(); i++) {
        parser::tokens::Token* token = direct_tokens->at(i);

        switch (token->get_token_type()) {
            case parser::tokens::TokenType::CHAR:
                buffer.push_back(token);

                {
                    parser::tokens::TokenChar* token_char = (parser::tokens::TokenChar*) token;

                    std::string string;

                    for (unsigned long int j = 0; j < buffer.size(); j++) {
                        switch (buffer.at(j)->get_token_type()) {
                            case parser::tokens::TokenType::CHAR:
                                {
                                    parser::tokens::TokenChar* tk_ch = (parser::tokens::TokenChar*) buffer.at(j);
                                    string.push_back(tk_ch->get_data());
                                }
                                break;
                            case parser::tokens::TokenType::POINT:
                                string.push_back('.');
                                break;
                            case parser::tokens::TokenType::NEGITIVE:
                                string.push_back('-');
                                break;
                            default:
                                break;
                        }
                    }

                    bool next_is_whitespace = true;
                    unsigned long int next_index = i + 1;
                    if (next_index < direct_tokens->size()) {
                        parser::tokens::Token* next = direct_tokens->at(next_index);

                        next_is_whitespace = (next->get_token_type() == parser::tokens::TokenType::WHITESPACE);
                    }

                    if (std::isdigit(token_char->get_data()) && next_is_whitespace) {
                        bool is_negitive = string.find("-") != -1;
                        std::string str = string;
                        if (is_negitive) {
                            str.replace(string.find("-"), 1, "");
                        }

                        double number = std::stod(str);

                        if (is_negitive) {
                            number *= -1.0;
                        }

                        parsered_tokens->push_back(new parser::NumberParsedToken(number));

                        buffer.clear();

                    } else if (next_is_whitespace) {
                        parser::ParsedToken* keyword_token = string_to_keyword(string);
                        if (keyword_token == nullptr) {
                            parsered_tokens->push_back(new parser::VarParsedToken(string));
                        } else {
                            parsered_tokens->push_back(keyword_token);
                        }

                        buffer.clear();

                    }

                }

                break;
            case parser::tokens::TokenType::ADD:
                parsered_tokens->push_back(new parser::BaseParsedToken(parser::ParsedTokenType::ADD));
                break;
            case parser::tokens::TokenType::SUBTRACT:
                parsered_tokens->push_back(new parser::BaseParsedToken(parser::ParsedTokenType::SUBTRACT));
                break;
            case parser::tokens::TokenType::MULTIPLIE:
                parsered_tokens->push_back(new parser::BaseParsedToken(parser::ParsedTokenType::MULTIPLIE));
                break;
            case parser::tokens::TokenType::DIVIDE:
                parsered_tokens->push_back(new parser::BaseParsedToken(parser::ParsedTokenType::DIVIDE));
                break;
            case parser::tokens::TokenType::MODULO:
                parsered_tokens->push_back(new parser::BaseParsedToken(parser::ParsedTokenType::MODULO));
                break;
            case parser::tokens::TokenType::POWER:
                parsered_tokens->push_back(new parser::BaseParsedToken(parser::ParsedTokenType::POWER));
                break;
            case parser::tokens::TokenType::POINT:
                buffer.push_back(token);
                break;
            case parser::tokens::TokenType::EQUAL:
                parsered_tokens->push_back(new parser::BaseParsedToken(parser::ParsedTokenType::EQUAL));
                break;
            case parser::tokens::TokenType::NEGITIVE:
                buffer.push_back(token);
                break;
            case parser::tokens::TokenType::WHITESPACE:
                break;
        }
    }

    return parsered_tokens;
}

parser::ParsedTokenType parser::ParsedToken::get_token_type() const {
    return this->token_type;
}

std::string parser::BaseParsedToken::string() const {
    
    switch (this->get_token_type()) {
        case parser::ParsedTokenType::ADD:
            return "ADD";
        case parser::ParsedTokenType::SUBTRACT:
            return "SUBTRACT";
        case parser::ParsedTokenType::MULTIPLIE:
            return "MULTIPLIE";
        case parser::ParsedTokenType::DIVIDE:
            return "DIVIDE";
        case parser::ParsedTokenType::MODULO:
            return "MODULO";
        case parser::ParsedTokenType::POWER:
            return "POWER";
        case parser::ParsedTokenType::EQUAL:
            return "EQUAL";
        case parser::ParsedTokenType::PRINT:
            return "PRINT";
        default:
            return "";
    }

}

double parser::NumberParsedToken::get_number() const {
    return this->number;
}

std::string parser::NumberParsedToken::string() const {
    std::string str("NUMBER(" + std::to_string(this->get_number()));
    str.push_back(')');
    return str;
}

std::string parser::VarParsedToken::get_name() const {
    return this->name;
}

std::string parser::VarParsedToken::string() const {
    std::string str("VAR(" + this->get_name());
    str.push_back(')');
    return str;
}
