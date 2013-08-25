#include <stdio.h>
#include <set>

using namespace std;

#define N 100


//with number repeat
void zuhe(int n, int m, int* path, int octave)
{
	//printf("n: %d, m: %d\n", n, m);
	if(m < 0 || n < 1)
		return;
	
	if(m == 0)
	{
		for (int i = 0; i < octave; i++)
		{
			printf("%d ", path[i]);
		}
		printf("\n");
	}
	else
	{
		zuhe(n-1, m, path, octave);
		path[octave] = n;
		zuhe(n, m-n, path, octave+1);	
	}
}


//with no number repeat
void zuhe2(int n, int m, int* path, int octave)
{
	// printf("n: %d, m: %d\n", n, m);
	// for (int i = 0; i < octave; i++)
	// {
	// 	printf("%d: %d ", i, path[i]);
	// }
	// printf("\n");

	if(m < 0 || n < 0)
		return;
	
	if(m == 0)
	{
		for (int i = 0; i < octave; i++)
		{
			printf("%d ", path[i]);
		}
		printf("\n");
	}
	else
	{
		zuhe2(n-1, m, path, octave);
		path[octave] = n;
		zuhe2(n-1, m-n, path, octave+1);	
	}
}


int main()
{
	int n = 5;
	int m = 8;
	int path[N];
	zuhe2(n, m, path, 0);
}
