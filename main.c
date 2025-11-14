//
// Created by Flytr on 13/11/2025.
//
#include "include/queue.h"
#include "include/parser.h"
#include <stdio.h>
#include <string.h>

void clean_stdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {

    parser_T *parser = init_parser();

    int again = 1;
    char expression[MAX_QUEUE_SIZE];

    do {
        printf("Inserisci l'espressione da valutare: ");

        if (fgets(expression, MAX_QUEUE_SIZE, stdin) == NULL) {
            break;
        }

        //pulisce il '\n' (invio)
        size_t len = strlen(expression);
        if (len > 0 && expression[len - 1] == '\n') {
            expression[len - 1] = '\0';
        } else if (len == MAX_QUEUE_SIZE - 1) {
            // L'input era troppo lungo, puliamo il resto del buffer
            printf("Attenzione: input troppo lungo, è stato troncato.\n");
            clean_stdin();
        }

        if (strlen(expression) == 0) {
            printf("Input vuoto, riprova.\n\n");
            continue;
        }

        parser_T *parser = init_parser();

        printf("\nIl risultato è: %.3f", evaluate(parser, expression));

        destroy_parser(parser);

        printf("\n\nVuoi valutare un'altra espressione? -- 1 (si) | 0 (no) --\n> ");

        if (fgets(expression, MAX_QUEUE_SIZE, stdin) == NULL) {
            break;
        }

        //controlliamo solo il primo carattere della risposta e il secondo per inserire la parola "no"
        //tra le parole di terminazione programma
        if (expression[0] == '0' || (expression[0] == 'n' && expression[1] == 'o')) {
            again = 0;
        } else {
            again = 1;
        }

        printf("\n");
    }while (again);


    destroy_parser(parser);

    return 0;
}
