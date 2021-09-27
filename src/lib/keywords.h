#ifndef KEYWORDS_H
#define KEYWORDS_H

#include <string>
#include <map>
#include "token.h"
#include "token_constants.h"

using namespace std;

class Keywords
{
public:
    static map<string, TokenType> kwmap;
};

#endif
