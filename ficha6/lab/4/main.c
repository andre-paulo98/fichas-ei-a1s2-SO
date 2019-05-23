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
#include <time.h>

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
    // <=> fopen(path, "a");
    int fd = open(path, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd == -1) {
        fprintf(stderr, "Failed to open file: '%s'\n", path);
        fprintf(stderr, "Internal error: %s\n", strerror(errno));
        exit(EXIT_IO_FAILURE);
    }

    time_t now;
    time(&now);

    struct tm *time_parts = localtime(&now);
    char buffer[25];
    strftime(buffer, 25, "%Y.%m.%d %H:%M:%S\n", time_parts);

    ssize_t to_write = strlen(buffer);
    if (write(fd, buffer, to_write) != to_write) {
        fprintf(stderr, "Failed to write\n");
    }
    printf("Done\n");

    close(fd);

	return 0;
}

