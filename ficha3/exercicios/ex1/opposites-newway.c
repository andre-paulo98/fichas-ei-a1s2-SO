#include <ctype.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>

#define MAX_WORDS 6

int main(int argc, char *argv[]) {

	char palavra[20];
	//					   0       1        2       3       4       5
	char* antonimos[MAX_WORDS] = {"big", "small", "short", "tall", "high", "low"};

	if(argc >= 2) {

		for(int j = 1; j < argc; j++){

			strcpy(palavra, argv[j]);
			// colocar a palavra em minuscula
			/*for(int i = 0; palavra[i]; i++){
				palavra[i] = tolower(palavra[i]);
			}*/


			for(int i = 0; i < MAX_WORDS; i++) {
				if(strcasecmp(antonimos[i], palavra) == 0) {

					int newIndex = i % 2 == 0 ? i + 1 : i - 1;

					printf("%s\n", antonimos[newIndex]);
					//strcpy(argv[j], antonimos[newIndex]);
				}
			}

		}




		
	}
	
	return 0;
}


