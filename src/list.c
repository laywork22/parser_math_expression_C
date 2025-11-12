//
// Created by laywork on 11/11/25.
//

#include "../include/list.h"

#include <stdlib.h>

list_T *create_list() {
    list_T *list = (list_T *) malloc(sizeof(list_T));

    if (!list) {
        perror("Lista non allocata");
        exit(EXIT_FAILURE);
    }

    list->head = NULL;
    list->counter = 0;

    return list;
}

void add_node(list_T *list, token_T *token) {
    node_T *node = malloc(sizeof(node_T));


    if (!node) {
        perror("Non non allocato");
        exit(EXIT_FAILURE);
    }

    node->tokens = token;
    node->next = NULL;

    if (!list_is_full(list)) {
        if (list_is_empty(list)) {
            list->head = node;
        } else {
            node_T *last_node = list->head;

            while (last_node->next != NULL) {
                last_node = last_node->next;
            }

            last_node->next = node;
            list->counter++;
        }
    } else {
        perror("Lista piena");
        exit(EXIT_FAILURE);
    }
}

/**
 *
 * @brief elimina il token passato come parametro
 * @param list
 * @param token
 */

//FIFO lista
int remove_node(list_T *list, token_T *token) {
    if (list_is_empty(list)) {
        return 0;
    }

    node_T *curr = list->head;
    node_T *prec = NULL;

    while (curr != NULL) {
        if (curr->tokens == token) {
            if (prec == NULL) {
                list->head = curr->next;
            } else {
                prec->next = curr->next;
            }

            free(curr);

            list->counter--;

            return 1;
        }
        prec = curr;
        curr = curr->next;
    }

    return 0;
}

int remove_node_head(list_T *list) {
    if (list_is_empty(list)) {
        return 0;
    }

    node_T *curr = list->head;

    if (curr->next == NULL) {
        list->head = NULL;
    }
    else {
        list->head = curr->next;
    }

    list->counter--;

    free(curr);

    return 1;
}

node_T *find_node(token_T *token) {
    return NULL;
}

list_T *destroy_list(list_T *list);

int list_is_empty(list_T *list);

int list_is_full(list_T *list);

