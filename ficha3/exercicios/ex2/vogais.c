#include <ctype.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

	char* vogais = "aeiou";
	(void)vogais;

	if(argc >= 2) {

		// para cada palavra dos argumentos
		for(int j = 1; j < argc; j++){ 

			int qtvogais = 0;

			for(size_t i = 0; i < strlen(argv[j]) ; i++) {

				for(int v = 0; v < 5; v++) {

					if(vogais[v] == tolower(argv[j][i])){
						qtvogais++;
					}

				}



			}

			printf("%s: %d vogais\n", argv[j], qtvogais);
			

		}




		
	}
	
	return 0;
}


