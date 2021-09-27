#include "gtest/gtest.h"

#include "src/lib/token.h"
#include "src/lib/lexer.h"
#include "src/lib/token_constants.h"

#include <string>
#include <iostream>

using namespace std;

struct TokenTestCase
{
    TokenType expectedType;
    string expectedLiteral;
};

TEST(Lexer_Test, NextTokenTest)
{
    const int NUM_OF_TEST = 8;
    Lexer *lexer = new Lexer("=+(){},;");
    TokenTestCase tests[NUM_OF_TEST] = {{COMPILER_ASSIGN, "="},
                                        {COMPILER_PLUS, "+"},
                                        {COMPILER_LPAREN, "("},
                                        {COMPILER_RPAREN, ")"},
                                        {COMPILER_LBRACE, "{"},
                                        {COMPILER_RBRACE, "}"},
                                        {COMPILER_COMMA, ","},
                                        {COMPILER_SEMICOLON, ";"}};

    for (int i = 0; i < NUM_OF_TEST; i++)
    {
        Token *token = lexer->next_token();
        EXPECT_EQ(*(token->get_type()), tests[i].expectedType) << "Wrong type: must: " << tests[i].expectedType << ", but: " << *(token->get_type());
        EXPECT_EQ(*(token->get_literal()), tests[i].expectedLiteral) << "Wrong literal: must: " << tests[i].expectedLiteral << ", but: " << *(token->get_literal());
    }
}
