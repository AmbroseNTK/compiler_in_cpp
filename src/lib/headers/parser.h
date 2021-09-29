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
    Statement *parse_statement();
    DecVarStatement *parse_dec_variable_statement();
    bool cur_token_is(TokenType type);
    bool peek_token_is(TokenType type);
    bool expect_peek(TokenType type);
};

#endif