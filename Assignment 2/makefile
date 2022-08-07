CC = gcc
CFLAGS = -Wall -pedantic -ansi -g
OBJ = main.o linkedlist.o play_area.o random_generator.o terminal.o game_condition.o snake_movement.o
EXEC = snake

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : main.c linkedlist.h play_area.h random_generator.h terminal.h game_condition.h snake_movement.h
	gcc -c main.c $(CFLAGS)

linkedlist.o : linkedlist.c linkedlist.h
	gcc -c linkedlist.c $(CFLAGS)

play_area.o : play_area.c play_area.h linkedlist.h random_generator.h
	gcc -c play_area.c $(CFLAGS)

random_generator.o : random_generator.c random_generator.h 
	gcc -c random_generator.c $(CFLAGS)

terminal.o : terminal.c terminal.h
	gcc -c terminal.c $(CFLAGS)

game_condition.o : game_condition.c game_condition.h linkedlist.h random_generator.h
	gcc -c game_condition.c $(CFLAGS)

snake_movement.o : snake_movement.c snake_movement.h terminal.h linkedlist.h
	gcc -c snake_movement.c $(CFLAGS)


clean:
	rm -f $(EXEC) $(OBJ)