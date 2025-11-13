//
// Created by laywork on 11/11/25.
//

#ifndef MATH_EXPRESSION_PARSER_EXPRESSION_TOKEN_H
#define MATH_EXPRESSION_PARSER_EXPRESSION_TOKEN_H

typedef enum {
    PLUS_TOKEN,
    MINUS_TOKEN,
    MUL_TOKEN,
    DIV_TOKEN,
    EQUALS_TOKEN,
    DOT_TOKEN,
    LEFT_PAREN_TOKEN,
    RIGHT_PAREN_TOKEN,
    UNARY_MINUS_TOKEN,
}tokens;

typedef struct ExpressionToken {
    tokens token;
    int priority;
}token_T;

token_T *init_token_T(tokens token, int priority);

#endif //MATH_EXPRESSION_PARSER_EXPRESSION_TOKEN_H