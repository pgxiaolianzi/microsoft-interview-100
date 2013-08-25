#include <stdio.h>


bool desideTree(int* a, int start, int end)
{
	if(start+1  >= end)
		return true;
	int t = start;
	while(t < end)
	{
		if(a[t] > a[end])
			break;
		t++;
	}
	int mid = t;
	while(t < end)
	{
		if(a[t] < a[end])
			break;
		t++;
	}
	if(t < end)
		return false;
	bool result1 = desideTree(a, start, mid-1);
	bool result2 = desideTree(a, mid, end-1);
	return (result1 && result2);
}


int main()
{
	int a[4] = {7, 4, 6, 5};
	bool result = desideTree(a, 0, 3);
	if(result)
		printf("true\n");
	else
		printf("false\n");
}
