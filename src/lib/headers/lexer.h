#ifndef LEXER_H
#define LEXER_H

#include <string>
#include "token.h"

class Lexer
{
protected:
    string input;
    int pos;
    int readPos;
    char ch;

public:
    Lexer(string const &input);
    string *get_input();
    int *get_pos();
    int *get_read_pos();
    char *get_ch();
    void read_char();
    Token *next_token();
    bool ch_is_letter();
    string read_identifier();
    TokenType lookup_ident(string const &ident);
    void skip_whitespace();
    string read_number();
    bool ch_is_digit();
    string preview_input(int next);
};

#endif