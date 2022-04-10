CC = gcc
CFLAGS = -Wall -pedantic -ansi
OBJ = main.o 
EXEC = program  

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : main.c 
	gcc -c main.c $(CFLAGS)

clean:
	rm -f $(EXEC) $(OBJ)

