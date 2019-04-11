
#include <string.h>

int count_letra(const char* haystack, char needle){

	int counter = 0;

	for(size_t i = 0; i < strlen(haystack); i++){

		if(haystack[i] == needle){
			counter++;
		}

	}

	return counter;
}