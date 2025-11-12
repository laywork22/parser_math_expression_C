//
// Created by laywork on 11/11/25.
//

#ifndef MATH_EXPRESSION_PARSER_LIST_H
#define MATH_EXPRESSION_PARSER_LIST_H
#include "expression_token.h"

typedef struct Node {
    token_T *tokens;
    struct Node *next;
}node_T;

typedef struct list {
    node_T *head;
    int counter;
} list_T;

list_T *create_list();

void add_node(list_T *list, token_T *token);

int remove_node(list_T *list,token_T *token);

int remove_node_head(list_T *list);

node_T *find_node(token_T *token);

list_T *destroy_list(list_T *list);

int list_is_empty(list_T *list);

int list_is_full(list_T *list);


node_T *create_node(token_T *token);

node_T *insert_node(node_T *node);

node_T *destroy_node(node_T *node);

#endif //MATH_EXPRESSION_PARSER_LIST_H