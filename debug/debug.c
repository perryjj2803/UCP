#include <stdio.h>
#include <stdlib.h>

/* function to draw the map */
char **draw_map(int row_map, int col_map)
{
	int i=0;
    int j=0;
	char **game_map;
	game_map = (char**)malloc((row_map) * sizeof(char*));

	for(i = 0; i < row_map; i++)
	{
		game_map[i] = (char*)malloc((col_map) * sizeof(char));
	}
	for(i=0; i < row_map; i++)
		{
			for(j=0; j < col_map; j++)
			{
				game_map[i][j] = "0";
			}
		}
		return game_map;
}

char **print_map(int row_map, int col_map, char **game_map)
{
	int i, j;

	for(i = 0; i < row_map; i++)
	{
		for(j = 0; j < col_map; j++)
		{
			printf("0");
		}
	}
	return 0;
}

void free_game_map(char **game_map, int col_map)
{
	int i;

	for(i = 0; i < col_map; i++)
	{
		free(game_map[i]);
	}
	free(game_map);
}

int main(int argc, char *argv[])
{
	int row_map, col_map, snake_length;
	char **game_map;
	
	/* converting all of the command line arguments from char* to int */
	row_map = atoi(argv[1])+2;
	col_map = atoi(argv[2])+2;
	snake_length = atoi(argv[3]);

	game_map = draw_map(row_map, col_map);

	print_map(row_map, col_map, game_map);

	free_game_map(game_map, col_map);

	return 0;
}

/*
int snake(int snake_length)
{
	char snake_parts;
	int snake_Xcords, snake_Ycords;
	int i, j;

	snake_parts = (char)malloc(snake_length * sizeof(char));
	snake_Xcords = (int)malloc(snake_length * sizeof(int));
	snake_Ycords = (int)malloc(snake_length * sizeof(int));

	snake_parts[0] = "#"
	snake_parts[snake_length - 1] = ">";
	for(i = 1; i < snake_length - 1; i++)
	{
		snake_parts[i] = "-"
	}
	for(j = 0; j < snake_length; j++)
	{
		snake_Ycord[j] = j+1
	}
	snake_Xcord[1]

	free(snake_parts);
}
*/



/*
	for(y = 0; y < row_map - 1; y++)
	{
		for(x = 0; x < col_map - 1; x++)
		{
			if(y == 0 || y == col_map - 1|| x == 0 || x == row_map - 1)
			{
				game_map[x][y] = '*';
			}
			else
			{
				game_map[x][y] = ' ';
			}
			printf("%c, %c, %c", row_map, col_map, snake_length);
		}
	
	}
	for(n = 0; n < col_map; n++)
	{
		free(game_map[n]);
	}
	free(game_map);
}
*/
