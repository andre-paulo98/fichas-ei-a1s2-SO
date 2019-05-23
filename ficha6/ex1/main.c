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
#include <sys/stat.h>
#include <fcntl.h>
#include <stdint.h>

#include "debug.h"
#include "memory.h"
#include "args.h"

#define EXIT_INVALID_ARGS 1
#define EXIT_IO_FAILURE 2

int main(int argc, char *argv[]){

	struct gengetopt_args_info args_info;
	if (cmdline_parser(argc,argv,&args_info) != 0){
		exit(1);
	}


	int fd = open(args_info.filename_arg, O_RDONLY);
	if (fd == -1) {
        fprintf(stderr, "Failed to open file: '%s'\n", args_info.filename_arg);
        fprintf(stderr, "Internal error: %s\n", strerror(errno));
        exit(EXIT_IO_FAILURE);
    }


    for (int i = 1; i <= args_info.num_arg; ++i){
    	uint8_t byte;
    	ssize_t n = read(fd, &byte, 1); 
    	if (n == -1){
			ERROR(EXIT_IO_FAILURE, "Failed to read");
    	} else if (n== 0) {
    		break; // EOF
    	}
    	printf("[#%03d] %02x\n", i, byte);
    }


    close(fd);


	return 0;
}

