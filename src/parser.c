//
// Created by laywork on 11/11/25.
//
#include "../include/parser.h"
#include "../include/expression_number.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

expression_T *init( void *value, data_type_T data_type) {
    expression_T *exp = malloc(sizeof(expression_T));

    if (!exp) return NULL;

    if (data_type == TOKEN_TYPE) {
        exp->data = (token_T *) value;
    }
    else if (data_type == AST_TYPE) {
        exp->data = (number_T *) value;
    }

    exp->type = data_type;

    return exp;
}

void destroy(expression_T *exp) {
    if (!exp) return;

    free(exp);
}

parser_T *init_parser() {
    parser_T *parser = (parser_T *) malloc(sizeof(parser_T));

    if (!parser) {
        perror("Impossibile allocare il parser\n");
        exit(1);
    }

    parser->operatorStack = init_stack_T();
    parser->outputQueue = init_queue_T();
    if (!parser->operatorStack || parser->outputQueue) {
        perror("Errore allocazione parser");
        exit(1);
    }

    return parser;
}

double evaluate(parser_T *parser, const char *expression) {
    list_T *tokens = tokenize(parser,expression);

    convert_to_RPN(parser,tokens);

    return evaluate_RPN();
}

list_T *tokenize(const parser_T *parser, const char *expression) {
    if (expression == NULL) {
        return NULL;
    }

    list_T *tokenizer = create_list();

    int exp_counter = -1;
    int exp_len = strlen(expression);
    char *nextValidExp = malloc(MAX_QUEUE_SIZE*sizeof(char));
    char *eptr;


    for (int i = 0; i < exp_len; i++) {
        char curr = expression[i];

        if (isdigit(curr) || curr == '.') {
            exp_counter++;
            nextValidExp[exp_counter] = curr;
            nextValidExp[exp_counter + 1] = '\0';
        }
        else if (curr == '-') {
            if (exp_counter >= 0) {
                double num = strtod(nextValidExp, &eptr);
                add_node(tokenizer, init(init_number_T(num), AST_TYPE));
                memset(&nextValidExp[0], 0, sizeof(char) * MAX_QUEUE_SIZE);
                exp_counter = -1; //stringa vuota
            }

            int is_unary = 0;

            if (is_stack_empty(parser->operatorStack)) {
                is_unary = 1;
            }
            else {
                expression_T *last_exp = peek_last(tokenizer);

                if (last_exp == NULL || last_exp->type == TOKEN_TYPE) {
                    const token_T *token = last_exp->data;

                    tokens tk = token->token;

                    if (tk != RIGHT_PAREN_TOKEN) {
                        is_unary = 1;
                    }
                }
            }
            if (is_unary) {
                add_node(tokenizer, init(init_token_T(UNARY_MINUS_TOKEN, 4), AST_TYPE));
            }
            else {
                add_node(tokenizer, init(init_token_T(MINUS_TOKEN, 2), AST_TYPE));

            }
        }
        else if (curr == '+' || curr == '*' ||  curr == '/' || curr == '('  || curr == ')' ) {
           if (exp_counter >= 0) {
               double num = strtod(nextValidExp, &eptr);
               add_node(tokenizer, init(init_number_T(num), AST_TYPE));
               memset(&nextValidExp[0], 0, sizeof(char) * MAX_QUEUE_SIZE);
               exp_counter = -1; //stringa vuota
           }
           if (curr == '+') {
               add_node(tokenizer, init(init_token_T(PLUS_TOKEN, 2), AST_TYPE));
           }
           else if (curr == '*') {
               add_node(tokenizer, init(init_token_T(MUL_TOKEN, 3), AST_TYPE));
           }
           else if (curr == '/') {
               add_node(tokenizer, init(init_token_T(DIV_TOKEN, 3), AST_TYPE));
           }
           else if (curr == '(') {
               add_node(tokenizer, init(init_token_T(LEFT_PAREN_TOKEN, 1), AST_TYPE));
           }
           else if (curr == ')') {
               add_node(tokenizer, init(init_token_T(RIGHT_PAREN_TOKEN, 1), AST_TYPE));
           }
        }
        else if (isspace(curr)) {
            if (exp_counter >= 0) {
                double num = strtod(nextValidExp, &eptr);
                add_node(tokenizer, init(init_number_T(num), AST_TYPE));
                memset(&nextValidExp[0], 0, sizeof(char) * MAX_QUEUE_SIZE);
                exp_counter = -1; //stringa vuota
            }
        }
        else {
            printf("Carrattere non valido: %c\n", curr);
        }
    }

    if (exp_counter >= 0) {
        double num = strtod(nextValidExp, &eptr);
        add_node(tokenizer, init(init_number_T(num), AST_TYPE));
    }

    free(nextValidExp);

    return tokenizer;
}

void convert_to_RPN(parser_T *parser, list_T *tkns) {
    if (list_is_empty(tkns)) {
        return;
    }

    node_T *curr = tkns->head;

    while (curr != NULL) {
        expression_T *exp = curr->exp;

        if (exp->type == AST_TYPE) {
            number_T *num = exp->data;
            enqueue(parser->outputQueue, num, exp->type);
        }
        else if (exp->type == TOKEN_TYPE) {
            token_T *token = exp->data;
            tokens tk = token->token;

            if (tk == LEFT_PAREN_TOKEN) {
                push_stack_T(*token, parser->operatorStack);
            }
            else if (tk == RIGHT_PAREN_TOKEN) {
                while (!is_stack_empty(parser->operatorStack) &&
                    get_top(parser->operatorStack)->token != LEFT_PAREN_TOKEN) {
                    token_T *tn = pop_stack_T(parser->operatorStack);
                    enqueue(parser->outputQueue, tn, TOKEN_TYPE);
                }

                if (!is_stack_empty(parser->operatorStack) &&
                    get_top(parser->operatorStack)->token == LEFT_PAREN_TOKEN) {
                    pop_stack_T(parser->operatorStack);
                }
            }
            else {
                while (!is_stack_empty(parser->operatorStack) &&
                    get_top(parser->operatorStack)->token != LEFT_PAREN_TOKEN &&
                        get_top(parser->operatorStack)->priority >= token->priority) {
                    token_T *tn = pop_stack_T(parser->operatorStack);
                    enqueue(parser->outputQueue, tn, TOKEN_TYPE);
                }

                push_stack_T(*token, parser->operatorStack);
            }
        }

        curr = curr->next;
    }

    while (!is_stack_empty(parser->operatorStack)) {
        token_T *tk = pop_stack_T(parser->operatorStack);

        enqueue(parser->outputQueue, tk, TOKEN_TYPE);
    }
}

double evaluate_RPN(parser_T *parser) {
    return 0.0;
}

void destroy_parser(parser_T *parser) {
    if (!parser) return;

    free(parser->operatorStack);
    free(parser->outputQueue);
    free(parser);
}
