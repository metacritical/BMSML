#include <ctype.h>
#define WORD_LENGTH 20
char *wordbuff[WORD_LENGTH];

/* char* expand_memory(char *buff){ */
/*     char *increaseChar = (char *) realloc(buff, sizeof(buff) * sizeof(char) + 1); */
/*     return increaseChar; */
/* } */

/* char* read_token(char *stream){ */
/*     return stream; */
/* } */

/* char *add_to_buffer(char c){ */
/*     if(sizeof(wordbuff) == 0){ */
/*         expand_memory(wordbuff); */
/*     }else{ */
/*         expand_memory(wordbuff); */
/*         wordbuff[sizeof(wordbuff)]; */
/*     } */
/* } */


char make_token(char c){

}




//Generates AST.
void parse_list(char* input){
    char *tok = input;
    if(*tok == '\0') return;

    if(*input == '('){
        //Match ( bracket.
        printf("\nMatched %c",*input );
        parse_list(++tok);
    }else if(*input == '+') {
        //Match Special Character.
        printf("\nMatched %c",*input );
        parse_list(++tok);
    }else if(*input == '-') {
        //Match Special Character.
        printf("\nMatched %c",*input );
        parse_list(++tok);
    }else if(*input == ' '){
        //Skip spaces.
        parse_list(++tok);
    }else if( isalpha(*tok) ){
        make_token(*tok);
        parse_list(++tok);
    }else{
        //Match this as atom.
        printf("\nMatch %c", *input);
        parse_list(++tok);
    }
}

/* if (*tok == '('){ printf("Yup ("); } */
/* else if( isalpha(*tok) ) { printf("Yup alpha"); } */
/* else if( isdigit(*tok) ){ printf("Yup a number"); } */
