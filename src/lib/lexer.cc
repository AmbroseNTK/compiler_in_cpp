#include "lexer.h"
#include <iostream>
#include <string>

#include "token_constants.h"
#include "keywords.h"

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
    this->skip_whitespace();

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

        if (this->ch_is_letter())
        {
            string ident = this->read_identifier();
            token = new Token(this->lookup_ident(ident), ident);
            return token;
        }
        else if (ch_is_digit())
        {
            if (this->preview_input(3) == "8=D")
            {
                cout << "has 8=D";
                token = new Token(COMPILER_ASSIGN, "=");
                this->read_char();
                this->read_char();
                this->read_char();
                return token;
            }
            else
            {
                token = new Token(COMPILER_INT, this->read_number());
                return token;
            }
        }
        else
        {
            token = new Token(COMPILER_ILLEGAL, string(1, this->ch));
        }
    }
    this->read_char();
    return token;
}

bool Lexer::ch_is_letter()
{
    return ('a' <= this->ch && this->ch <= 'z' || 'A' <= this->ch && this->ch <= 'Z' || this->ch == '_');
}

string Lexer::read_identifier()
{
    int pos = this->pos;
    while (this->ch_is_letter())
    {
        this->read_char();
    }
    return this->input.substr(pos, this->pos - pos);
}

TokenType Lexer::lookup_ident(string const &ident)
{
    try
    {
        TokenType token = Keywords::kwmap.at(ident);
        return token;
    }
    catch (const std::exception &e)
    {
        return COMPILER_IDENT;
    }
}

void Lexer::skip_whitespace()
{
    while (this->ch == ' ' || this->ch == '\t' || this->ch == '\n' || this->ch == '\r')
    {
        this->read_char();
    }
}

string Lexer::read_number()
{
    int pos = this->pos;
    while (this->ch_is_digit())
    {
        this->read_char();
    }
    return this->input.substr(pos, this->pos - pos);
}

bool Lexer::ch_is_digit()
{
    return '0' <= this->ch && this->ch <= '9';
}

string Lexer::preview_input(int next)
{
    if (this->pos + next < this->input.length())
    {
        return this->input.substr(this->pos, next);
    }
    return "";
}