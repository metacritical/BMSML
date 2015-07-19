#include <ctype.h>
#include "utils.h"

//Make Token
char make_token(char c){
    return 'c';
}

//Make a number or integer from a string.
Object *make_atom_from_string(char *c, char type){
    Array a;
    Array *Arry = create_array(&a, 5, type);

    //Check if the char is '-', then set signedness Negative.
    //And move the pointer to the number.
    if( type == 'i' && *c == '-'){
        Arry->signedness = NEGATIVE;
        c++;
    };

    //Condition 1 : if the char is a number. then collect all numbers
    //if a '.' is encountered set Array type as float and continue.
    if(isdigit(*c)){
        do{
            insert_into_array(Arry, *c);
            c++;

            if(*c == '.'){
                Arry->type = 'f';
                insert_into_array(Arry, *c);
                c++;
            }

        }while(isdigit(*c));
    }

    //Print Number.
    if(Arry->type == 'i'){
        return createInteger(array_to_int(Arry));
    }else if(Arry->type == 'f'){
        return createFraction(array_to_float(Arry));
    }else return nullObject();
}

//Generates AST.
Object *parse(char* input){
    char *tok = input;
    if(*tok == '\0') return nullObject();

    if(*input == ' '){ //Skip spaces
        parse(++tok);
    }else if( (*tok == '-' && isdigit(*(tok+1)) ) || isdigit(*tok) ){ //
        return make_atom_from_string(tok, 'i');
    }

    return parse(++tok);
}

Object *eval(Object *expression){
    return expression;
}

void print(Object *result){
    if(result->type == Integer)
        printf("%ld", result->Data.atom.integer.val);
    else if(result->type == Fraction)
        printf("%lf", result->Data.atom.fraction.val);
    else if(result->type == NIL && result->Data.atom.nil.val == NULL)
        printf("nil");
}
