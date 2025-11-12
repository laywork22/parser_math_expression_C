//
// Created by laywork on 11/11/25.
//
#include <stdio.h>
#include "../include/queue.h"

#include <stdlib.h>

queue_T *init_queue_T(queue_T *queue) {
    queue = (queue_T *) malloc(sizeof(queue_T));
    if (!queue) {
        perror("Malloc queue error");
        exit(EXIT_FAILURE);
    }

    queue->outputQueue = (void *) malloc(sizeof(void *) * MAX_QUEUE_SIZE);

    queue->type = (data_type_T *) malloc(sizeof(data_type_T) * MAX_QUEUE_SIZE);

    if (!queue->outputQueue || !queue->type) {
        free(queue->outputQueue);
        free(queue->type);
        free(queue);
        exit(EXIT_FAILURE);
    }

    queue->head = 0;
    queue->tail = 0;
    queue->counter = 0;

    return queue;
}

queue_T *dequeue(queue_T *queue) {
    if (queue_is_empty(queue)) {
        fprintf(stderr, "Coda vuota, impossibile eliminare token/numeri\n");
        exit(EXIT_FAILURE);
    }

    void *data = queue->outputQueue[queue->head];

    

    queue->head = (queue->head + 1) % MAX_QUEUE_SIZE;

    return queue;
}

void enqueue(queue_T *queue, void *value, data_type_T data_type) {
    if (queue_is_full(queue)) {
        fprintf(stderr, "Coda piena, impossibile aggiungere token/numeri\n");
        exit(EXIT_FAILURE);
    }


    queue->outputQueue[queue->tail] = value;
    queue->type[queue->tail] = data_type;

    queue->tail = (queue->tail + 1) % MAX_QUEUE_SIZE;

    queue->counter--;
}

void *get_first_from_queue_T(queue_T *queue) {
    if (queue_is_empty(queue)) {
        return NULL;
    }

    return queue->outputQueue[queue->head];
}

int queue_is_empty(queue_T *queue) {
    return queue->counter == 0;
}

int queue_is_full(queue_T *queue) {
    return (queue->tail + 1) % MAX_QUEUE_SIZE == queue->head;
}

queue_T *destroy_queue_T(queue_T *queue) {
    free(queue->outputQueue);
    free(queue->type);
    free(queue);

    return NULL;
}