#include <stdio.h>
#include <stdlib.h>
#include "string_utils.h"

#define EXIT_INVALID_ARGS 2

static int isVogal(char v);
static int isConsoant(char v);

static int countVogal(const char* word);
static int countConsoant(const char* word);

int main(int argc, char const *argv[]){

    if (argc == 1) {
        fprintf(stderr, "Invalid number of arguments\n");
        fprintf(stderr, "Usage: %s <word>...\n", argv[0]);
        exit(EXIT_INVALID_ARGS);
    }

    for (int i = 1; i < argc; ++i) {
        printf("%s : %d vogals\n", argv[i], countVogal(argv[i]));
    }
    return 0;
}