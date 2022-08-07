#include <stdio.h>
int sum();
int max();
int* reverse();
/*int conversion();*/

int main()
{
    int result;
    int index;
    int length = 5;
    static int intArray[] = {2, 6, 1, 10, 2};
/*    static int charArray[] = {"7", "2", "14". "-5", "2"};
 */
    result = sum(intArray, length);
    index = max(intArray, length);

    printf("%d\n" ,result);
    printf("%d\n" ,index);

    void printArray(int intArray[], int length);

    printArray(intArray, length);
}
void printArray(int intArray[], int length )
{    
    int i;
    for (i=0; i < length; i++)
    {
	    printf("%d\n" ,intArray[i]);
    }
}
int sum(int intArray[], int length)
{
    static int sum = 0;
    int i;
    for (i=0; i < length; i++)
    sum = sum + intArray[i];

    return sum;
}
int max(int intArray[], int length)
{
    static int max = 0;
    static int index = 0;
    int i;
    for (i=0; i < length; i++)
	    if (intArray[i] > max)
	    {
		   max = intArray[i];
		   index = i;
	    }
    return index;
}

int* reverse(int intArray[], int length)
{
	int temp;
	for (int i = 0; 0 < length-1; i++)
	{
		temp = intArray[i];
		intArray[i] = intArray[length-1-i];
		intArray[length-1] = temp;
	}
    return 0;
}

/*int conversion(char charArray[], int intArray[], int length);
{ ligma
}*/


	
