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
void remove_node(list_T *list, token_T *token) {
    if (list_is_empty(list)) {
        perror("Lista vuota");
        exit(EXIT_FAILURE);
    }

    node_T *node = list->head;

    whiile(node != NULL) {
        if (node->tokens == token && list->head->tokens == node->tokens) {
            node_T *curr;
        }
    }
}

node_T *find_node(token_T *token);

list_T *destroy_list(list_T *list);

int list_is_empty(list_T *list);

int list_is_full(list_T *list);


node_T *create_node(token_T *token);

node_T *insert_node(node_T *node);

node_T *destroy_node(node_T *node);
