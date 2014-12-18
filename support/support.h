#if __APPLE__
#include <editline/readline.h>
#elif __gnu_linux__
#include <readline/readline.h>
#endif

//Custom Inclusions
#include "bender_ascii.h"
#include "color.h" /* Color Header*/

//prompt ≺≻
//Increment Repl prompt line count.
char prompt[] = "\n[0]≻ ";
int repl_line_count = 0;

incr_prompt(){
    repl_line_count += 1;
    sprintf(prompt,"\n[%d]≻ ", repl_line_count);
    return(0);
}

//Experimental Test Code.
test_func(char* input){
    while (*input){
        printf("This : %c\n",*input);
        *input++;
    }
}
