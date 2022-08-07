CC = gcc
CFLAGS = -Wall -pedantic -ansi -g
OBJ = main.o play_area.o random_generator.o terminal.o snake_movement.o game_condition.o
EXEC = snake

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : main.c play_area.h random_generator.h terminal.h
	gcc -c main.c $(CFLAGS)

play_area.o : play_area.c play_area.h
	gcc -c play_area.c $(CFLAGS)

random_generator.o : random_generator.c random_generator.h
	gcc -c random_generator.c $(CFLAGS)

terminal.o : terminal.c terminal.h
	gcc -c terminal.c $(CFLAGS)

snake_movement.o : snake_movement.c snake_movement.h terminal.h
	gcc -c snake_movement.c $(CFLAGS)

game_condition.o : game_condition.c game_condition.h
	gcc -c  game_condition.c $(CFLAGS)


clean:
	rm -f $(EXEC) $(OBJ)

