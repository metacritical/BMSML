#include <ctype.h>

//Generates AST.
void parse_list(char* input){
    char *tok = input;

    if(*tok == '\0') return;

    if(*input == '('){
        //Match ( bracket.
        printf("%c", *tok);
        parse_list(++tok);
    }else if(*input == '+') {
        //Match Special Character.
        printf("%c", *input);
        parse_list(++tok);
    }else if(*input == ' '){
        //Skip spaces.
        parse_list(++tok);
    }else{
        //Match this as atom.
        printf("%c", *input);
        parse_list(++tok);
    }
}


char* read_token(char *stream){
    return stream;
}


/* if (*tok == '('){ printf("Yup ("); } */
/* else if( isalpha(*tok) ) { printf("Yup alpha"); } */
/* else if( isdigit(*tok) ){ printf("Yup a number"); } */
