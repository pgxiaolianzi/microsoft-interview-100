#include <stdio.h>

#define N 30


int main()
{
	// int array[N];
	// for(int i = 0; i < N; i++)
	// 	array[i] = i+1;
	int cursor[N];
	int delEle = 10;
	for(int i = 0; i < N; i++)
		cursor[i] = (i + 1)%N;

	int count = 1;
	int point = delEle;
	cursor[point -1] = cursor[point];
	int del;
	int prior;
	while(count < 14)
	{
		printf("%d ", point);
		prior = point;
		for (int i = 0; i < delEle-1; ++i)
		{
			prior = cursor[prior];
		}
		point = cursor[prior];
		cursor[prior] = cursor[point];
		count++;
	}
	printf("%d\n", point);
	return 1;
}