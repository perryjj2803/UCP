#include <stdio.h>
int sum();
int max();
void reverse();
int conversion();

int main()
{
    int result;
    int index;
    int length = 5;
    static int intArray[] = {2, 6, 3, 4, 1};
    static int charArray[] = {"7", "2", "14". "-5", "2"};
 
    result = sum(intArray, length);
    index = max(intArray, length);

    printf("%d\n" ,result);
    printf("%d\n" ,index);

    reverse(intArray, length);


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
void reverse(int intArray[], int length)
{
	for (int i = length-1; i>=0; i--)
	{
		printf("%d ", intArray[i]);
	}
	return;
}
int conversion(char charArray[], int intArray[], int length);
{


	
