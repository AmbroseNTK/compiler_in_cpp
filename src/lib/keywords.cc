#include "keywords.h"

map<string, TokenType> Keywords::kwmap = {
    {"job", COMPILER_FUNCTION},
    {"has", COMPILER_DEC_VARIABLE},
    {"have", COMPILER_DEC_VARIABLE}};