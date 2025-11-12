//
// Created by laywork on 11/11/25.
//
#include "../include/stack.h"

#include <stdio.h>
#include <stdlib.h>

stack_T *init_stack_T() {
    stack_T *stack = malloc(sizeof(stack_T));

    stack->counter = 0;
    stack->size = MAX_STACK_SIZE;

    return &stack;
}


void push_stack_T(const token_T token, stack_T *stack){
    if (is_stack_full(stack)) {
        printf("Stack pieno: impossibile aggiungere altri elementi. Espressione troppo grande\n");
        exit(1);
    }

    stack->operatorStack[stack->counter] = token;

    stack->counter++;

}

token_T pop_stack_T( stack_T *stack) {
    if (is_stack_empty(stack)) {
        printf("Stack vuoto: impossibile eliminare elementi\n");
        exit(1);
    }

    int index = stack->counter - 1;

    stack->counter--;

    return stack->operatorStack[index];
}

token_T get_top(const stack_T *stack) {
    if (is_stack_empty(stack)) {
        printf("Stack vuoto: impossibile eseguire l'operazione di top\n");
        exit(1);
    }

    return stack->operatorStack[stack->counter - 1];
}

int is_stack_full(const stack_T *stack) {
    return stack->counter == stack->size;
}

int is_stack_empty(const stack_T *stack) {
    return stack->counter == 0;
}