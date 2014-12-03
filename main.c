#include <stdio.h>

/* Buffer for user input */

static char buff[2048];

int main(int argc, char** argv) {
	puts("BMSML Version 0.0.1");
	puts("~ Dedicated to Esha ~ Most suave girl in the whole universe.");
	puts("Press Ctrl+C to Exit this infite rat hole :D");

	/* Repl Loop Starts Here */
	while(1) {
		fputs("BMSML\n|> ", stdout);
		fgets(buff, 2048, stdin);

		printf("you typed : %s", buff);
	}

}































