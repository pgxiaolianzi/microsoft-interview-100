#include <stdio.h>

#define N 30


int main()
{
	int array[8] = {1, -2, 3, 10, -4, 7, 2, -5};
	int s = 0;
	int ms = 0, mi = 0, mj = 0;
	int start = 0, end = start;
	for(int i = 0; i < 8; i++)
	{
		if(array[i] < 0 && ms < s)
		{
			ms = s;
			mi = start;
			mj = end;
			//printf("tag\n");
		}
		if(s + array[i] < 0)
		{
			s = 0;
			start = i+1;
			end = start;
		}
		else
		{
			end++;
			s += array[i];
		}
	}
	printf("%d %d %d\n", mi, mj, ms);
	return 0;
}