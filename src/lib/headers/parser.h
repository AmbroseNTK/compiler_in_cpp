#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include "token.h"
#include "ast.h"

class Parser
{
protected:
    Lexer *lexer;
    Token *curToken;
    Token *peekToken;

public:
    void next_token();
    Program *parse_program();
};

#endif