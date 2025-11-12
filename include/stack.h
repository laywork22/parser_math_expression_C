//
// Created by laywork on 11/11/25.
//

#ifndef MATH_EXPRESSION_PARSER_STACK_H
#define MATH_EXPRESSION_PARSER_STACK_H

#include "expression_token.h"
#define MAX_STACK_SIZE 100

typedef struct Stack {
    token_T operatorStack[MAX_STACK_SIZE];
    int size;
    int counter;
} stack_T;

stack_T init_stack_T();

void push_stack_T(token_T token, stack_T *stack);

token_T pop_stack_T(stack_T *stack);

token_T get_top(const stack_T *stack);

int is_stack_full(const stack_T *stack);

int is_stack_empty(const stack_T *stack);



#endif //MATH_EXPRESSION_PARSER_STACK_H