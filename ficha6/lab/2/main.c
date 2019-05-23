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
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "debug.h"
#include "memory.h"

#define EXIT_INVALID_ARGS 1
#define EXIT_IO_FAILURE 2

int main(int argc, char *argv[]){
    if (argc != 2) {
        fprintf(stderr, "Invalid number of arguments\n");
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        exit(EXIT_INVALID_ARGS);
    }

    char *path = argv[1];
    int fd = open(path, O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Failed to open file: '%s'\n", path);
        fprintf(stderr, "Internal error: %s\n", strerror(errno));
        exit(EXIT_IO_FAILURE);
    }

    printf("OK\n");

    close(fd);

	return 0;
}

