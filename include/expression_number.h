//
// Created by laywork on 11/11/25.
//

#ifndef MATH_EXPRESSION_PARSER_EXPRESSION_NUMBER_H
#define MATH_EXPRESSION_PARSER_EXPRESSION_NUMBER_H

typedef struct ExpressionNumber {
    double value;
    int priority;
}number_T;

number_T *init_number_T(double value);

#endif //MATH_EXPRESSION_PARSER_EXPRESSION_NUMBER_H