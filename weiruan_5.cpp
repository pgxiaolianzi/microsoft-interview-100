#include <stdio.h>


void headAdjust(int* a, int n)
{
	int k = n/2 - 1;
	int minI;
	for(int i = k; i >= 0; i--)
	{
		minI = 2*i;
		if(a[minI+1] < a[minI])
			minI = minI+1;
		if(a[minI] < a[i])
		{
			int temp = a[i];
			a[i] = a[minI];
			a[minI] = temp;
		}
	}
}


int main()
{
	int a[8] = {4, 2, 3, 5, 7, 1, 8, 6};
	int k = 4;
	int* minist = new int[k];
	for(int i = 0; i < k; i++)
	{
		headAdjust(a, 8-i);
		minist[i] = a[0];
		int temp = a[0];
		a[0] = a[7-i];
		a[7-i] = temp;
	}
	for(int i = 0; i < k; i++)
		printf("%d ", minist[i]);
	printf("\n");	
	return 0;
}
