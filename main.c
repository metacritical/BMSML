#include <stdio.h>
#include <stdlib.h> //To get free() memory function.
#include <stdbool.h> //For Boolean bool true false macros.
#include "support/support.h"

int main(int argc, char** argv) {
    cprint(ascii_art, BASH_YEL);
    cprint("BMSML Version 0.0.1\n", BASH_RED);
    cprint("Press Ctrl+C or type (exit) to come out of this infinite rat hole :P\n", BASH_CYN);

    static char delim[] = "+-*/^";
    /* Repl Loop Starts Here */
    while( true ) {
        char* line = readline(prompt);

        if ( !strcmp( line , "(exit)" ) ){
            puts("Bye.");
            break;
        }else{
            cprint("You typed : ", BASH_RED);
            printf("%s", (char *)line);
            test_func(line);
        }

        add_history(line);
        incr_prompt();

        //since line returns is allocated with malloc();
        //the caller should free() the line when it has finished with it.
        free(line);
    }
}
