//
// Created by laywork on 11/11/25.
//
#include "../include/parser.h"

#include <stdio.h>
#include <stdlib.h>

void init_parser(parser_T *parser) {
    parser = (parser_T *) malloc(sizeof(parser));

    if (!parser) {
        perror("Impossibile allocare il parser\n");
        exit(1);
    }

    parser->operatorStack = init_stack_T();
    parser->outputQueue = init_queue_T();
    if (!parser->operatorStack || parser->outputQueue) {
        perror("Errore allocazione parser");
        exit(1);
    }
}

double evaluate(char *expression) {
    list_T *tokens = tokenize(expression);

    convert_to_RPN(tokens);

    return evaluate_RPN();
}

list_T *tokenize(char *expression) {
    return NULL;
}

void convert_to_RPN(list_T *tokens) {

}

double evaluate_RPN() {
    return 0.0;
}
