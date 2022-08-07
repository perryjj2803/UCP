CC = gcc
CFLAGS = -Wall -pedantic -ansi -g
OBJ = main.o area.o neighbours.o
EXEC = life

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : main.c area.h
	gcc -c main.c $(CFLAGS)

area.o : area.c area.h
	gcc -c area.c $(CFLAGS)

neighbours.o : neighbours.c neighbours.h area.h
	gcc -c neighbours.c $(CFLAGS)

clean:
	rm -f $(EXEC) $(OBJ)