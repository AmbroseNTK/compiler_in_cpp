#include "ast.h"

string *Program::token_literal()
{
    if (this->statements.size() > 0)
    {
        return this->statements.at(0).token_literal();
    }
}

string *LetStatement::token_literal()
{
    return this->token->get_literal();
}

void LetStatement::statement_node() {}

string *Identifier::token_literal()
{
    return this->token->get_literal();
}

void Identifier::expression_node() {}
