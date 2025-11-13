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

    return list;
}

void add_node(list_T *list, expression_T *exp) {
    node_T *node = create_node(exp);

    if (!node) {
        perror("Nodo non allocato");
        exit(EXIT_FAILURE);
    }

    node->exp = exp;
    node->next = NULL;

    if (list_is_empty(list)) {
        list->head = node;
    } else {
        node_T *last_node = list->head;

        while (last_node->next != NULL) {
            last_node = last_node->next;
        }

        last_node->next = node;
    }
}

int remove_node(list_T *list, const expression_T *exp) {
    if (list_is_empty(list)) {
        return 0;
    }

    node_T *curr = list->head;
    node_T *prec = NULL;

    while (curr != NULL) {
        if (curr->exp == exp) {
            if (prec == NULL) {
                list->head = curr->next;
            } else {
                prec->next = curr->next;
            }

            free(curr);

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

    free(curr);

    return 1;
}

expression_T *peek_head(list_T *list) {
    if (list_is_empty(list)) return NULL;

    return list->head->exp;
}

expression_T *peek_last(list_T *list) {
    node_T *curr = list->head;

    while (curr->next != NULL) {
        curr = curr->next;
    }

    return curr->exp;
}

node_T *destroy_node(node_T *node) {
    if (!node) return NULL;

    node = destroy_node(node->next);

    free(node->exp);
    free(node);

    return NULL;
}

list_T *destroy_list(list_T *list) {
    if (list == NULL) {
        return NULL;
    }

    list->head = destroy_node(list->head);

    free(list);

    return NULL;
}

int list_is_empty(list_T *list) {
    return list->head == NULL;
}

node_T *create_node(expression_T *exp) {
    node_T *node = malloc(sizeof(node_T));

    if (!node) return NULL;

    node->exp = exp;
    node->next = NULL;

    return node;
}

