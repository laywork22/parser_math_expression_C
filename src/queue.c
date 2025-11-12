//
// Created by laywork on 11/11/25.
//
#include <stdio.h>
#include "../include/queue.h"
#include "../include/expression_token.h"
#include <stdlib.h>

#include "../include/expression_number.h"

queue_T *init_queue_T() {
    queue_T *queue = malloc(sizeof(queue_T));
    if (!queue) {
        perror("Malloc queue error");
        exit(EXIT_FAILURE);
    }

    queue->outputQueue = (expression_T *) malloc(sizeof(expression_T) * MAX_QUEUE_SIZE);

    if (!queue->outputQueue ) {
        free(queue->outputQueue);
        free(queue);
        exit(EXIT_FAILURE);
    }

    queue->head = 0;
    queue->tail = 0;
    queue->counter = 0;

    return queue;
}

expression_T *dequeue(queue_T *queue) {
    if (queue_is_empty(queue)) {
        fprintf(stderr, "Coda vuota, impossibile eliminare token/numeri\n");
        exit(EXIT_FAILURE);
    }

    expression_T *data = &queue->outputQueue[queue->head];

    queue->head = (queue->head + 1) % MAX_QUEUE_SIZE;
    queue->counter--;

    return data;
}

void enqueue(queue_T *queue, void *value, const data_type_T data_type) {
    if (queue_is_full(queue)) {
        fprintf(stderr, "Coda piena, impossibile aggiungere token/numeri\n");
        exit(EXIT_FAILURE);
    }

    if (!value) {
        return;
    }

    if (data_type == TOKEN_TYPE) {
        token_T *token_value = (token_T *) value;
        queue->outputQueue[queue->tail].data = token_value;
        queue->outputQueue[queue->tail].type = data_type;
    }
    else if (data_type == AST_TYPE) {
        number_T *num_value = (number_T*) value;
        queue->outputQueue[queue->tail].data = num_value;
        queue->outputQueue[queue->tail].type = data_type;
    }

    queue->tail = (queue->tail + 1) % MAX_QUEUE_SIZE;

    queue->counter--;
}

expression_T get_first_from_queue_T(queue_T *queue) {
    if (queue_is_empty(queue)) {
        const expression_T empty = {NULL,  NULL_TYPE};
        perror("Attenzione: la coda non ha token.");
        return empty;
    }

    return queue->outputQueue[queue->head];
}

int queue_is_empty(const queue_T *queue) {
    return queue->counter == 0;
}

int queue_is_full(queue_T *queue) {
    return (queue->tail + 1) % MAX_QUEUE_SIZE == queue->head;
}

queue_T *destroy_queue_T(queue_T *queue) {
    if (queue_is_empty(queue)) {
        free(queue);
        return NULL;
    }

    for (int i = 0, idx = queue->head;  i < queue->counter; i++) {
        free(queue->outputQueue[idx].data);

        idx = (idx + 1) % MAX_QUEUE_SIZE;
    }

    free(queue->outputQueue);
    free(queue);

    return NULL;
}