#include <iostream>

#include "../lib/lexer.h"
#include "../lib/repl.h"

using namespace std;

int main()
{
    Repl repl = Repl();

    cout << "Hello! This is DMaMa programming language" << endl
         << "Feel free to type in CLI" << endl;

    repl.start();

    return 0;
}