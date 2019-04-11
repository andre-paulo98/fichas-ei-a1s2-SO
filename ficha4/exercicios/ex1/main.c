#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "conta_letra.h"

#define EXIT_INVALID_ARGS 2

int main(int argc, char const *argv[]){

	if(argc != 3 || strlen(argv[2]) > 1){
		fprintf(stderr, "\tUsage must be: %s <word> <letter>\n", argv[0]);
		exit(EXIT_INVALID_ARGS);
	}

	int counter = count_letra(argv[1], argv[2][0]);

	fprintf(stdout, "The word '%s' has %d '%c'\n", argv[1], counter, argv[2][0]);


}