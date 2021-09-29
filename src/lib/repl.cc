#include "repl.h"
#include <iostream>
#include <string>
#include "lexer.h"
#include "token_constants.h"

using namespace std;

void Repl::start()
{
    while (true)
    {
        cout << this->prompt << " ";
        string input = "";
        getline(cin, input);
        Lexer *lexer = new Lexer(input);
        Token *token = lexer->next_token();
        while (*(token->get_type()) != COMPILER_EOF)
        {
            cout << *(token->get_type()) << ": " << *(token->get_literal()) << endl;
            token = lexer->next_token();
        }
    }
}