//
// Created by laywork on 11/11/25.
//

#ifndef MATH_EXPRESSION_PARSER_PARSER_H
#define MATH_EXPRESSION_PARSER_PARSER_H

#include "list.h"
#include "queue.h"
#include "stack.h"

typedef struct parser {
    queue_T *outputQueue;
    stack_T *operatorStack;
}parser_T;

void init_parser(parser_T *parser);

double evaluate(char *expression);

list_T *tokenize(char *expression);

void convert_to_RPN(list_T *tokens);

double evaluate_RPN();

#endif //MATH_EXPRESSION_PARSER_PARSER_H