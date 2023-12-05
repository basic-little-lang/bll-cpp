
#ifndef _PARSER_HPP_
#define _PARSER_HPP_

#include <vector>
#include <string>
#include "tokens.hpp"

namespace parser {

    enum class ParsedTokenType {
        ADD,
        SUBTRACT,
        DIVIDE,
        MULTIPLIE,
        MODULO,
        POWER,
        NUMBER,
        EQUAL,
        PRINT,
        COPY,
        VAR,
    };

    class ParsedToken {
        protected:
            ParsedTokenType token_type;
        public:
            ParsedToken(ParsedTokenType token_key) : token_type(token_key) {};
            virtual ~ParsedToken() = default;
            ParsedTokenType get_token_type() const;
            virtual std::string string() const = 0;
    };

    class BaseParsedToken : public ParsedToken {
        public:
            BaseParsedToken(ParsedTokenType token_type) : ParsedToken(token_type) {};
            std::string string() const;
    };

    class NumberParsedToken : public ParsedToken {
        protected:
            double number;
        public:
            NumberParsedToken(double number) : ParsedToken(ParsedTokenType::NUMBER), number(number) {};
            std::string string() const;
            double get_number() const;
    };

    class VarParsedToken : public ParsedToken {
        protected:
            std::string name;
        public:
            VarParsedToken(std::string name) : ParsedToken(ParsedTokenType::VAR), name(name) {};
            std::string string() const;
            std::string get_name() const;
    };


    std::vector<ParsedToken*>* convert(std::vector<tokens::Token*>* direct_tokens);

}

#endif
