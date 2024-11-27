CC = gcc
CFLAGS = -Wall -O2
DEPS = struct.h
OBJ = arbre_cartesien.c
EXEC = main

all : $(EXEC)

%.o: %.c $(DEPS)
	$(CC) -o $@ -c $< $(CFLAGS)

main : main.o $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)


clean :
	rm -rf $(EXEC) *.o
	rm -rf $(EXEC) main
	rm -rf $(EXEC) */*.o