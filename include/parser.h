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

parser_T *init_parser();

double evaluate(parser_T *parser, const char *expression);

list_T *tokenize(const parser_T *parser, const char *expression);

void convert_to_RPN(parser_T *parser,list_T *tokens);

double evaluate_RPN(const parser_T *parser);

void destroy_parser(parser_T *parser);

expression_T *init( void *value, data_type_T data_type);

void destroy(expression_T *exp);

#endif //MATH_EXPRESSION_PARSER_PARSER_H