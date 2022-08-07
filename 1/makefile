CC=gcc
CFLAGS= -g -ansi -pedantic -Wall -Werror
DEPS = map.h random.h terminal.h move.h

ifneq "$(UNBEATABLE)" "1"
OBJ = snake.o map.o random.o terminal.o move.o
else
OBJ = snake.o map.o random.o terminal.o moveU.o
endif

%.0: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

snake: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(EXEC) $(OBJ)
