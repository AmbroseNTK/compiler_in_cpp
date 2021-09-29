#include "headers/keywords.h"

map<string, TokenType> Keywords::kwmap = {
    {"job", COMPILER_FUNCTION},
    {"has", COMPILER_DEC_VARIABLE},
    {"have", COMPILER_DEC_VARIABLE},
    {"ok", COMPILER_TRUE},
    {"no", COMPILER_FALSE},
    {"if", COMPILER_IF},
    {"else", COMPILER_ELSE},
    {"<=8", COMPILER_RETURN},
    {"is", COMPILER_ASSIGN}};