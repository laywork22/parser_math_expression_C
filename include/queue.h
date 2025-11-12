//
// Created by laywork on 11/11/25.
//

#ifndef MATH_EXPRESSION_PARSER_QUEUE_H
#define MATH_EXPRESSION_PARSER_QUEUE_H

#define MAX_QUEUE_SIZE 100

typedef enum {
    TOKEN_TYPE,
    AST_TYPE
}data_type_T;

typedef struct Queue {
    void **outputQueue;
    data_type_T *type;
    int head;
    int tail;
    int counter;
}queue_T;

queue_T *init_queue_T(queue_T *queue);

queue_T *dequeue(queue_T *queue);

void enqueue(queue_T *queue, void *value, data_type_T data_type);

void *get_first_from_queue_T(queue_T *queue);

int queue_is_empty(queue_T *queue);

int queue_is_full(queue_T *queue);

queue_T *destroy_queue_T(queue_T *queue);


#endif //MATH_EXPRESSION_PARSER_QUEUE_H