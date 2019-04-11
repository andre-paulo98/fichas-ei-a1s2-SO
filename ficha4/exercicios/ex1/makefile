# flags para o compilador
CFLAGS = -std=c11 -Wall -Wextra

# ficheiros objecto
OBJS = main.o conta_letra.o
PROGRAM = conta-letra

all: $(PROGRAM)

debugon: CFLAGS += -D SHOW_DEBUG
debugon: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CC) -o $@ $(OBJS)

depend:
	gcc -MM *.c

# Lista de dependências dos ficheiros código fonte
conta_letra.o: conta_letra.c
main.o: main.c conta_letra.h

# Indica como transformar um ficheiro .c num ficheiro .o
.c.o:
	$(CC) $(CFLAGS) -c $<

# remove ficheiros sem interesse
clean:
	rm -f *.o core.* *~ $(PROGRAM)
