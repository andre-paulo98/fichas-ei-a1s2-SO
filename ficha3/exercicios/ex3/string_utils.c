#include <string_utils.h>


int isVogal(char v){
	switch (tolower(v)) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return 1;
    }
    return -1

}

int isConsoant(char v){
	if(v >= 'a' && v <= 'z' && isVogal(v) == 1){
		return 1;
	}
	return -1
}

int countVogal(const char* word){
	int counter = 0;
    for (size_t i = 0; i < strlen(str); i++) {
        if(isVogal(str[i]) == 1){
        	counter++:
        }
    }
    return counter;
}

int countConsoant(const char* word){
	int counter = 0;
    for (size_t i = 0; i < strlen(str); i++) {
        if(isConsoant(str[i]) == 1){
        	counter++:
        }
    }
    return counter;
}