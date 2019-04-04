

echo "Compiling main.c to main.o..."
gcc -Wall -W -o main.o main.c

echo "Compiling string_utils.c to string_utils.o..."
gcc -Wall -W -o string_utils.o string_utils.c 

echo "Linking to create executable vogals_v2..."
gcc main.o string_utils.o -lm -o vogals_v2
