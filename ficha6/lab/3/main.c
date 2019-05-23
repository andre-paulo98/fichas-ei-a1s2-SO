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
    // <=> fopen(path, "w");
    int fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        fprintf(stderr, "Failed to open file: '%s'\n", path);
        fprintf(stderr, "Internal error: %s\n", strerror(errno));
        exit(EXIT_IO_FAILURE);
    }
    for (int i = 1; i <= 10; ++i) {
        ssize_t to_write = sizeof(int);
        if (write(fd, &i, to_write) != to_write) {
            fprintf(stderr, "Failed to write\n");
        }
    }
    char buffer[5];
    for (int i = 1; i <= 10; ++i) {
        snprintf(buffer, 5, "%d\n", i);
        ssize_t to_write = strlen(buffer);
        if (write(fd, buffer, to_write) != to_write) {
            fprintf(stderr, "Failed to write\n");
        }
    }


    printf("Done\n");

    close(fd);

	return 0;
}

