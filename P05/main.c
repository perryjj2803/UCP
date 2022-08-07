#include <stdio.h>
int main(int argc, char** argv)
{
	int ch;
	if(argc != 3)
	{
		perror("Invalid input, please specify an input and output file\n");
	}
	else
	{
	FILE *inFile = fopen(argv[1], "r");
	FILE *outFile = fopen(argv[2], "w");

	do
        {
		ch = fgetc(inFile);
		if(ch != EOF)
		{
			fputc((char)ch, outFile);
			fputc('-', outFile);
		}
	} while(ch != EOF);
	fclose(inFile);
	fclose(outFile);

	}
	return 0;
}
/*	do
	{
ligma		ch = fgetc(inFile);
		if(ch != EOF)
		{
		    fputc((char)ch, outFile);
		    fputc('-', outFile);
		}
	} while(ch != EOF);
	fclose(argv[1]);
	fclose(argv[2]);

}*/


