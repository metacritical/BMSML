#include <stdbool.h>
#include <ctype.h>
#include "utils.h"

//Make a number or integer from a string.
Object *make_atom(char *c, Type type){
    Array a;
    Array *Arry = create_array(&a, 5, type);

    //Check if the char is '-', then set signedness Negative.
    //And move the pointer to the number.
    if( type == Integer && *c == '-'){
        Arry->signedness = NEGATIVE;
        c++;
    };

    switch(type){
        //Condition 1 : if the char is a number. then collect all numbers
        //if a '.' is encountered set Array type as float and continue.
    case Integer :
        if(isdigit(*c)){
            do{
                insert_into_array(Arry, *c);
                c++;

                if(*c == '.'){
                    Arry->type = Fraction;
                    insert_into_array(Arry, *c);
                    c++;
                }

            }while(isdigit(*c));
        } break;

        //Condition 2: If the char starts with a " then it is probably a string.
    case String : do{
            insert_into_array(Arry, *c);
            ++c;
        }while(*c != '\0');

        break;

    case Symbol : while(*c != ' ' || *c != '\0' || *c != ')'){
            insert_into_array(Arry, *c);
            ++c;
        } break;


    default : return nullObject(); break;
    }

    //Make the appropriate kind of atom.
    switch(Arry->type){
    case Integer  : return createInteger(array_to_int(Arry));    break;
    case Fraction : return createFraction(array_to_float(Arry)); break;
    case String   : return createString(array_to_string(Arry));  break;
    case Symbol   : return createSymbol(array_to_string(Arry));  break;
    default : return nullObject(); break;
    }

}

Object *makeList(char *tok){
    while(*tok == ' ')
        ++tok;
    //Check if it is a non empty list.
    if(*tok == ')'){
        return emptyList();
    }else{
        Object *list = emptyList();
        return list;
    }
}


//Generates AST.
Object *parse(char* input){
    char *tok = input;

    if(*tok == '\0') return nullObject();

    if( (*tok == '-' && isdigit(*(tok+1)) ) || isdigit(*tok) ){ //
        return make_atom(tok, Integer);
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
    }else if(*tok == '"'){
        return make_atom(tok, String);
    }else if( *tok == '(' ){
        return makeList(++tok);
    }

    return parse(++tok);
}

Object *eval(Object *exprn){
    if(exprn->type == Cons){
        Cell *cell = exprn->Data.cell;
        if(cell->car->type == NIL && cell->cdr->type == NIL)
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
    case String   : puts(result->Data.atom.string.val); break;
    default       : puts("\n"); break;
    }

}
