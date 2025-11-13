cmake_minimum_required(VERSION 4.0)
project(math_expression_parser C)

set(CMAKE_C_STANDARD 11)

add_executable(math_expression_parser
        include/expression_number.h
        include/expression_token.h
        include/parser.h
        include/list.h
        include/stack.h
        include/queue.h
        src/list.c
        src/expression_number.c
        src/expression_token.c
        src/stack.c
        src/queue.c
        src/parser.c
        main.c
)
