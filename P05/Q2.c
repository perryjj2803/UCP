#include <stdio.h>
int main(int argc, char** argv)
{
	int ch;
	if(argc != 2)
	{
		perror("Invalid input, please specify an input file\n");
	}
	else
	{
		FILE *inFile = fopen(argv[1], "r");
