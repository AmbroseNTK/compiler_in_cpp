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
};

#endif