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
    virtual string *token_literal() = 0;
};

class Identifier
{
protected:
    Token *token;
    string *value;

public:
    void expression_node();
    string *token_literal();
};

class LetStatement
{
protected:
    Token *token;
    Identifier *name;
    Expression *value;

public:
    void statement_node();
    string *token_literal();
};

#endif