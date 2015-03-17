#include <stdio.h>
#include <stdlib.h> //To get free() memory function.
#include <stdbool.h> //For Boolean bool true false macros.
#include "support/support.h"

int main(int argc, char** argv) {
    print_banner();

    /* Repl Loop Starts Here */
    while( true ) {
        char* line = (char *)readline(prompt);

        if ( !strcmp( line , "(exit)" ) ){
            puts("Bye.");
            break;
        }else{
            cprint("You typed : ", BASH_RED);
            printf("%s", line);
            parse_list(line);
        }

        //add the expression to history and increment prompt
        add_history(line);
        increment_prompt();

        //since line returns is allocated with malloc();
        //the caller should free() the line when it is finished with it.
        free(line);
    }
    return 0;
}
