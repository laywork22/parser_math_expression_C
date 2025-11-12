//
// Created by laywork on 11/11/25.
//

#include <stdlib.h>

number_T *init_expression_number(double value) {
    number_T number = (number_T*) malloc(sizeof(number_T));

    number->value = value;
    number->priority = 0;

    return number;
}
