#include "headers/ast.h"

string *Program::token_literal()
{
    if (this->statements.size() > 0)
    {
        return this->statements.at(0).token_literal();
    }
}

vector<Statement> *Program::get_statements()
{
    return &this->statements;
}

DecVarStatement::DecVarStatement(Token *token)
{
    this->token = token;
}

string *DecVarStatement::token_literal()
{
    return this->token->get_literal();
}

void DecVarStatement::statement_node() {}

void DecVarStatement::set_name(Identifier *name)
{
    this->name = name;
}

void DecVarStatement::set_expression(Expression *expression)
{
    this->value = expression;
}

Identifier::Identifier(Token *token, string *value)
{
    this->token = token;
    this->value = value;
}

string *Identifier::token_literal()
{
    return this->token->get_literal();
}

void Identifier::expression_node() {}
