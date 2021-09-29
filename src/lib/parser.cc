#include "headers/parser.h"
#include "headers/ast.h"
#include "headers/token.h"
#include "headers/token_constants.h"

Program *Parser::parse_program()
{
    Program *program = new Program();
    while (*this->curToken->get_type() != COMPILER_EOF)
    {
        Statement *statement = this->parse_statement();
        if (statement != nullptr)
        {
            program->get_statements()->push_back(*statement);
        }
        this->next_token();
    }

    return program;
}

Statement *Parser::parse_statement()
{
    TokenType type = *this->curToken->get_type();
    if (type == COMPILER_DEC_VARIABLE)
    {
        return this->parse_dec_variable_statement();
    }
    return nullptr;
}

DecVarStatement *Parser::parse_dec_variable_statement()
{
    DecVarStatement *statement = new DecVarStatement(this->curToken);
    if (this->expect_peek(COMPILER_IDENT))
    {
        return nullptr;
    }

    statement->set_name(new Identifier(this->curToken, this->curToken->get_literal()));

    if (this->expect_peek(COMPILER_ASSIGN))
    {
        return nullptr;
    }

    while (this->cur_token_is(COMPILER_SEMICOLON))
    {
        this->next_token();
    }

    return statement;
}

void Parser::next_token()
{
    this->curToken = this->peekToken;
    this->peekToken = this->lexer->next_token();
}

bool Parser::cur_token_is(TokenType type)
{
    return *this->curToken->get_type() == type;
}

bool Parser::peek_token_is(TokenType type)
{
    return *this->peekToken->get_type() == type;
}

bool Parser::expect_peek(TokenType type)
{
    if (this->peek_token_is(type))
    {
        this->next_token();
        return true;
    }
    return false;
}