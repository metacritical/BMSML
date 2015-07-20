#include <stdbool.h>
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

Object *makeList(char *tok){
    while(*tok == ' ')
        ++tok;

    if(*tok == ')'){
        return emptyList();
    }

    return emptyList();
}

//Generates AST.
Object *parse(char* input){
    char *tok = input;

    if(*tok == '\0') return nullObject();

    if( (*tok == '-' && isdigit(*(tok+1)) ) || isdigit(*tok) ){ //
        return make_atom_from_string(tok, 'i');
    }else if( *tok  == '#'){
        //If the char starts with a #, then it is a boolean
        //Create a true or false object. These are singletons or Atomss.
            ++tok;
            switch(*tok){
            case 't': return boolObject(true); break;
            case 'f': return boolObject(false); break;
            default:
                printf("God Knows if it is Boolean");
                exit(1);
            }
    }else if( *tok == '(' ){
        return makeList(++tok);
    }

    return parse(++tok);
}

Object *eval(Object *exprn){
    if(exprn->type == Cons){
        if(exprn->Data.cell->car->type == NIL && exprn->Data.cell->cdr->type == NIL)
            return nullObject();
    }

    return exprn;
}

void print(Object *result){
    switch(result->type){

    case Integer  : printf("%ld", result->Data.atom.integer.val); break;
    case Fraction : printf("%lf", result->Data.atom.fraction.val); break;
    case Boolean  : result->Data.atom.boolean.val ? puts("#t") : puts("#f"); break;
    case NIL      : puts("nil"); break;
    default       : puts("\n"); break;
    }

}
