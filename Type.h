//
// Created by Синицын Алексей on 30.10.2024.
//

#ifndef UNTITLED8_TYPE_H
#define UNTITLED8_TYPE_H


enum class Type {
    LINE, //          \n

    SUBZONE, //          :

    ASSIGNMENT, //          =

    EQUALLY, //          ==
    NOT_EQUAL, //          !=
    LESS, //          <
    MORE, //          >
    LESS_EQUAL, //          <=
    MORE_EQUAL, //          >=

    PLUS, //          +
    MINUS, //          -
    MULTIPLY, //          *
    DIVIDE, //          /
    REST, //          %

    IDENTIFIER, //          index_i

    INT_VALUE, //          123213
    FLOAT_VALUE, //          5310.1231
    SYMBOL_VALUE, //          'v'
    STR_VALUE //          "value"
};


#endif //UNTITLED8_TYPE_H
