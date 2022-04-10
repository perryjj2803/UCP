#include <stdio.h>
int powersOf2(int numTimes);
int main()
{
	int numTimes;
	int result;
	printf("How many times to run the power function:\n");
	scanf("%d", &numTimes);

	result = powersOf2(numTimes);

	printf("%d\n" ,result);
	return 0;
}
int powersOf2(int numTimes)
{
	int i; 
	static int exponent = 1;
	for(i=1; i<=numTimes; i++) 
	{	
		exponent = exponent*2;
	}
		#ifdef DEBUG
		printf("%d" ,exponent);
		#endif
		return exponent;
}

