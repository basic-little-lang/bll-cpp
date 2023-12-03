
#ifndef _TOKENS_HPP_
#define _TOKENS_HPP_

#include <vector>
#include <string>

namespace parser {
    namespace tokens {

        enum class TokenType {
            ADD,
            SUBTRACT,
            DIVIDE,
            MULTIPLIE,
            MODULO,
            POWER,
            NEGITIVE,
            EQUAL,
            CHAR,
            POINT,
            WHITESPACE,
        };

        extern const char COMMENT_CHAR;

        class Token {
            protected:
                TokenType token_type;
            public:
                Token(TokenType token_type) : token_type(token_type) {};
                virtual ~Token() = default;
                TokenType get_token_type() const;
                virtual std::string string() const = 0;
        };

        class TokenBase : public Token {
            public:
                TokenBase(TokenType token_type) : Token(token_type) {};
                std::string string() const;
        };

        class TokenChar : public Token {
            protected:
                char data;
            public:
                TokenChar(char data) : Token(TokenType::CHAR), data(data) {};
                char get_data() const;
                std::string string() const;

        };

        std::vector<Token*>* tokenize_string(std::string *str);

    }
}


#endif
