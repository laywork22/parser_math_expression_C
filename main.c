//
// Created by Flytr on 13/11/2025.
//
#include "include/list.h"
#include "include/queue.h"
#include "include/stack.h"
#include "include/parser.h"
#include <stdio.h>

int main() {

    parser_T *parser = init_parser();

    char expression[MAX_QUEUE_SIZE];

    printf("Inserisci l'espressione da valutare: ");
    scanf("%s", expression);

    printf("\nIl risultato è: %.3f", evaluate(parser, expression));

    destroy_parser(parser);

    return 0;
}
