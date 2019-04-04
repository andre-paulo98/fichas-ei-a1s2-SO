#include <ctype.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

	// needs to have atleast one argument
	char palavra[20];


	if(argc >= 2) {

		for(int j = 1; j < argc; j++){

			strcpy(palavra, argv[j]);

			for(int i = 0; palavra[i]; i++){
				palavra[i] = tolower(palavra[i]);
			}


			if (strcmp(palavra, "big") == 0){
				strcpy(palavra, "small");
			} else if (strcmp(palavra, "small") == 0){
				strcpy(palavra, "big");


			} else if (strcmp(palavra, "short") == 0){
				strcpy(palavra, "tall");
			} else if (strcmp(palavra, "tall") == 0){
				strcpy(palavra, "short");


			} else if (strcmp(palavra, "high") == 0){
				strcpy(palavra, "low");
			} else if (strcmp(palavra, "low") == 0){
				strcpy(palavra, "high");
			} else {
				printf("'%s' word not found! ", palavra);
				return 0;
			}

			printf("%s", palavra);


		}

		
	}

	



	
	return 0;
}

