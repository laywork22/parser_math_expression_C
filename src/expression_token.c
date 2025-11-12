//
// Created by laywork on 11/11/25.
//
#include "../include/expression_token.h"

token_T init_token_T(const tokens token, const int priority) {
    token_T tk;

    tk.token = token;
    tk.priority = priority;

    return tk;
}
