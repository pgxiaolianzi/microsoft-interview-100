#include <stdio.h>
#include <set>

using namespace std;

#define N 50


int main()
{
	int n = 17;
	int fib[N];
	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2; i < n; i++)
	{
		fib[i] = fib[i-1] + fib[i-2];
		printf("%d ", fib[i]);	
	}
	printf("\n");
}
