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

    int again = 1;
    char expression[MAX_QUEUE_SIZE];

    do {
        printf("Inserisci l'espressione da valutare: ");
        scanf("%s", expression);

        printf("\nIl risultato è: %.3f", evaluate(parser, expression));

        printf("\nVuoi valutare un'altra espressione? -- 1 (si) | 0 (no) --\n");

        scanf("%d", &again);

    }while (again);


    destroy_parser(parser);

    return 0;
}
