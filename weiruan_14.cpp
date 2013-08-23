#include <stdio.h>

#define N 20
#define  T(X, Y, i) (Y & (1<<i)) && (X+=(Y<<i))

void getAddNumber(int* a, int n, int sum)
{
	int i = 0, j = n-1;
	while (i < j)
	{
		int t = a[i] + a[j];
		if(t == sum)
		{
			printf("%d %d\n", a[i], a[j]);
			break;
		}
		else if(t < sum)
			i++;
		else
			j--;
	}
	if(i >= j)
		printf("can't find this two numbers!\n");
}


int main()
{
	int array[6] = {1, 2, 4, 7, 11, 15};
	int sum = 9;
	getAddNumber(array, 6, sum);
	return 0;
}