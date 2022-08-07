CC = gcc
CFLAGS = -Wall -pedantic -ansi -g
OBJ = main.o linkedlist.o
EXEC = snake

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : main.c linkedlist.h
	gcc -c main.c $(CFLAGS)

linkedlist.o : linkedlist.c linkedlist.h
	gcc -c linkedlist.c $(CFLAGS)

clean:
	rm -f $(EXEC) $(OBJ)