#include <stdio.h>
int factorialCalc(int);
int main(void)
{
    int userNum;
    

    printf("Please enter a number:\n");
    scanf("%d", &userNum);

    int factorial = factorialCalc(userNum);
    printf("The factorial of %d = %d", userNum, factorial);
    
}

int factorialCalc(int userNum)
{
    int i; 
    int factorial = 1;
    if (userNum < 0)
        printf("Invalid number (cannot factorial a number less than 0");
    else
        for(i = 1; i <= userNum; ++i)
        {
            factorial *= i;
	}
    return factorial;
}	
