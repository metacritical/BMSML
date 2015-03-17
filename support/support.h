#if __APPLE__
#include <editline/readline.h>
#elif __gnu_linux__
#include <readline/readline.h>
#include <readline/history.h>
#endif

//Custom Inclusions
#include "bender_ascii.h"
#include "color.h" /* Color Header*/
#include "prompt.h"
#include "parser.h"


void print_banner(){
  char msg[] =
    "Press Ctrl+C or type (exit)"
    "to exit this infinite rat hole :P\n";

    cprint(ascii_art, BASH_YEL);
    cprint("BMSML Version 0.0.1\n", BASH_RED);
    cprint(msg, BASH_CYN);
}
