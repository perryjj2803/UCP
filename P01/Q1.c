#include <stdio.h>
int main(void)
    {
	int firstNum, secondNum;

	printf("Please enter two numbers\n");
	scanf("%d%d", &firstNum, &secondNum);

        if(firstNum%secondNum == 0)
		printf("Divisible");
	else
		printf("Not divisible");
    }
