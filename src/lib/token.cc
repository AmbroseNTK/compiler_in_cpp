#include "token.h"

Token::Token(TokenType const &type, string const &literal)
{
    this->type = type;
    this->literal = literal;
}

TokenType *Token::get_type()
{
    return &this->type;
}

string *Token::get_literal()
{
    return &this->literal;
}