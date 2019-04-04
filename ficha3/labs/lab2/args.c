#include <stdio.h>

int main(int argc, char *argv[])
{
   
   int i;
      
   printf("\n\n");
   printf("Numero de argumentos: %d\n", argc);
   printf("\n");
   printf("Listagem dos argumentos\n");
   for (i=0; i<argc; i++)
     printf("\tArgumento[%d]= %s\n", i, argv[i]);
   printf("\n");
   
   return 0;   
}

