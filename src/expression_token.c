//
// Created by laywork on 11/11/25.
//
#include "../include/expression_token.h"

#include <stdlib.h>

token_T *init_token_T(tokens token, int priority) {
    token_T *tk = (token_T *)malloc(sizeof(token_T));

    tk->token = token;
    tk->priority = priority;

    return tk;
}
