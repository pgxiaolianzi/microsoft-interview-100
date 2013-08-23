#include <stdio.h>

#define N 20
#define  T(X, Y, i) (Y & (1<<i)) && (X+=(Y<<i))

int sumArray(int n, int& sum)
{
	sum += n;
	(n > 0) && sumArray(n-1, sum);
}

int twoFact(int n)
{
  	int r = 0;
	T(r, n, 0); T(r, n, 1); T(r, n, 2); T(r, n, 3);
	T(r, n, 4); T(r, n, 5); T(r, n, 6); T(r, n, 7);
	T(r, n, 8); T(r, n, 9); T(r, n, 10); T(r, n, 11);
	T(r, n, 12); T(r, n, 13); T(r, n, 14); T(r, n, 15);
	T(r, n, 16); T(r, n, 17); T(r, n, 18); T(r, n, 19);
	T(r, n, 20); T(r, n, 21); T(r, n, 22); T(r, n, 23);
	T(r, n, 24); T(r, n, 25); T(r, n, 26); T(r, n, 27);
	T(r, n, 28); T(r, n, 29); T(r, n, 30); T(r, n, 31);
	//printf("%d\n", r);
  	return r;
}

int sumArray2(int n)
{
	return (twoFact(n) + n) >> 1;
}


int main()
{
	int n = 5;
	//int sum = 0;
	//sumArray(n, sum);
	int sum = sumArray2(n);
	printf("%d\n", sum);
	return 0;
}