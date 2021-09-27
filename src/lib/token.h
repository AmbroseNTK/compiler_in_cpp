#ifndef TOKEN_H
#define TOKEN_H

#include <string>

using namespace std;

typedef string TokenType;

class Token
{
protected:
    TokenType type;
    string literal;

public:
    Token(TokenType const &type, string const &literal);
    TokenType *get_type();
    string *get_literal();
};

#endif