//
// Created by laywork on 11/11/25.
//

#ifndef MATH_EXPRESSION_PARSER_QUEUE_H
#define MATH_EXPRESSION_PARSER_QUEUE_H

#define MAX_QUEUE_SIZE 100

typedef enum {
    TOKEN_TYPE,
    AST_TYPE,
    NULL_TYPE
}data_type_T;

typedef struct Expression {
    void *data;
    data_type_T type;
}expression_T;

typedef struct Queue {
    expression_T *outputQueue;
    int head;
    int tail;
    int counter;
}queue_T;

queue_T *init_queue_T();

expression_T *dequeue(queue_T *queue);

void enqueue(queue_T *queue, void *value, data_type_T data_type);

expression_T get_first_from_queue_T(queue_T *queue);

int queue_is_empty(const queue_T *queue);

int queue_is_full(queue_T *queue);

queue_T *destroy_queue_T(queue_T *queue);


#endif //MATH_EXPRESSION_PARSER_QUEUE_H