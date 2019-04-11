#include "string_utils.h"
#include <string.h>
#include <ctype.h>

static int is_vogal(char letter);
static int is_consonant(char letter);


int count_vogals(const char *s) {
    int i, total = 0, max = strlen(s);
    for (i = 0; i < max; i++) {
        if (is_vogal(s[i])) {
            total++;
        }
    }
    return total;
}

int count_consonants(const char *s) {
    int i, total = 0, max = strlen(s);
    for (i = 0; i < max; i++) {
        if (is_consonant(s[i])) {
            total++;
        }
    }
    return total;
}

int is_vogal(char letter) {
    switch (tolower(letter)) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return 1;
    }
    return 0;
}

int is_consonant(char letter) {
    if (is_vogal(letter)) {
        return 0;
    }
    int ch = tolower(letter);
    return ch >= 'a' && ch <= 'z';
}

