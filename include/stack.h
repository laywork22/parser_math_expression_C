//
// Created by laywork on 11/11/25.
//

#ifndef MATH_EXPRESSION_PARSER_STACK_H
#define MATH_EXPRESSION_PARSER_STACK_H

#include "expression_token.h"

typedef struct Stack {
    token_T *operatorStack;
} stack_T;

stack_T *init_stack_T();

stack_T *destroy_stack_T(stack_T *stack);

void push_stack_T(token_T *token, stack_T *stack);

token_T *pop_stack_T(token_T *token, stack_T *stack);

token_T *get_top(stack_T *stack);

#endif //MATH_EXPRESSION_PARSER_STACK_H