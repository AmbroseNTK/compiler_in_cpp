#ifndef AST_H
#define AST_H

#include <string>
#include <vector>
#include "token.h"

using namespace std;

class Node
{
public:
    virtual string *token_literal() = 0;
};

class Statement : public Node
{
public:
    virtual void statement_node() = 0;
};

class Expression : public Node
{
public:
    virtual void expression_node() = 0;
};

class Program
{
protected:
    vector<Statement> statements;

public:
    string *token_literal();
    vector<Statement> *get_statements();
};

class Identifier
{
protected:
    Token *token;
    string *value;

public:
    Identifier(Token *token, string *valuue);
    void expression_node();
    string *token_literal();
};

class DecVarStatement : public Statement
{
protected:
    Token *token;
    Identifier *name;
    Expression *value;

public:
    DecVarStatement(Token *token);
    void statement_node();
    string *token_literal();
    void set_name(Identifier *name);
    void set_expression(Expression *value);
};

#endif