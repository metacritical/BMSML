#include "main.h"
#include "support/support.h"
/* Buffer for user input */

int main(int argc, char** argv) {
	cprint("BMSML Version 0.0.1\n", BASH_RED);
	cprint("Press Ctrl+C to Exit this infite rat hole :P\n", BASH_CYN);

	/* Repl Loop Starts Here */
	while( true ) {
		char* line = readline("\n|> ");

		add_history(line);

		cprint("You typed : ", BASH_RED);
		printf("%s", line);

		//since line returns is allocated with malloc();
		//the caller should free() the line when it has finished with it.
		free(line);
	}
}
