/**
* @file main.c
* @brief Description
* @date 2018-1-1
* @author name of author
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "debug.h"
#include "memory.h"
#include "conta_letra.h"
#include "args.h"

int main(int argc, char *argv[]){
	/* Disable warnings */
	(void)argc; (void)argv;

	struct gengetopt_args_info args_info;
	if (cmdline_parser(argc,argv,&args_info) != 0){
		exit(1);
	}

	int counter = count_letra(args_info.string_arg, args_info.letra_arg[0]);

	fprintf(stdout, "The word '%s' has %d '%c'\n", args_info.string_arg, counter, args_info.letra_arg[0]);


	// para limpar a memória
	cmdline_parser_free(&args_info);


	return 0;
}

