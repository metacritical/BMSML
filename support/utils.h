#include <stdio.h>
#include <stdlib.h>
#include "primitive.h"

char *type_of_token(int t){
    char *type;

    switch( t ){
    case 0:
        type = "NIL";
        break;
    case 1:
        type = "Integer";
        break;
    case 2:
        type = "Fraction";
        break;
    case 3:
        type = "String";
        break;
    case 4:
        type = "Boolean";
        break;
    case 5:
        type = "Symbol";
        break;
    case 6:
        type = "Cons";
        break;
    }

    return type;
};

//Dynamic Character Array.
typedef struct {
    int size;
    int capacity;
    int signedness;
    int _expand_capacity;
    char type;
    char *char_array;
}Array;

Array *create_array(Array *this, int capacity, char type){
    this->size = 0;
    this->capacity = capacity;
    this->_expand_capacity = capacity;
    this->char_array = calloc(this->capacity, sizeof(char) );

    switch(type){
    case 'i':
        this->type = 'i';
        this->signedness = POSITIVE;
        break;
    case 'c':
        this->type = 'c';
        break;
    }

    return this;
}

void expand_array(Array *array){
    array->capacity = array->capacity + array->_expand_capacity;
    array->char_array = realloc(array->char_array, sizeof(char) * array->capacity);
}


void free_Array(Array *array){
    free(array->char_array);
    array = NULL;
    assert(array == NULL);
}

Array *insert_into_array(Array *this, char elem){
    if(this->size >= this->capacity){
        expand_array(this);
    }

    this->char_array[this->size] = elem;
    this->size++;
    return this;
}

void set_array_to_float(Array *arry){
    arry->type = 'f';
}

long int array_to_int(Array *arry){
    long int number = 0;
    int sign = arry->signedness;
    for(int i=0; i <= (arry->size)-1; i++){
        number = (number * 10) + (arry->char_array[i] - '0');
    }

    free_Array(arry);
    return sign * number;
}

double array_to_float(Array *arry){
    int sign = arry->signedness;
    double fraction = atof(arry->char_array);
    free_Array(arry);
    return sign * fraction;
}

Array *set_value_at_array(Array *arry, int *pos , char *val){
    arry->char_array[(int)pos] = (int)val;
    return arry;
}
