#include "lexer.h"
#include <iostream>
#include <string>

#include "token_constants.h"

using namespace std;

Lexer::Lexer(string const &input)
{
    this->input = input;
    this->readPos = 0;
    this->pos = 0;
    this->read_char();
}

void Lexer::read_char()
{
    if (this->readPos >= this->input.length())
    {
        this->ch = 0;
    }
    else
    {
        this->ch = this->input[this->readPos];
    }
    this->pos = this->readPos++;
}

Token *Lexer::next_token()
{
    Token *token = nullptr;
    switch (this->ch)
    {
    case '=':
        token = new Token(COMPILER_ASSIGN, string(1, this->ch));
        break;
    case ',':
        token = new Token(COMPILER_COMMA, string(1, this->ch));
        break;
    case ';':
        token = new Token(COMPILER_SEMICOLON, string(1, this->ch));
        break;
    case '(':
        token = new Token(COMPILER_LPAREN, string(1, this->ch));
        break;
    case ')':
        token = new Token(COMPILER_RPAREN, string(1, this->ch));
        break;
    case '{':
        token = new Token(COMPILER_LBRACE, string(1, this->ch));
        break;
    case '}':
        token = new Token(COMPILER_RBRACE, string(1, this->ch));
        break;
    case '+':
        token = new Token(COMPILER_PLUS, string(1, this->ch));
        break;
    case 0:
        token = new Token(COMPILER_EOF, "");
    default:
        break;
    }
    this->read_char();
    return token;
}