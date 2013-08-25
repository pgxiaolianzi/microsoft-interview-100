#include <stdio.h>
#include <set>

using namespace std;



int main()
{
	char s[256] = "abaccdeff";
	bool exist[512];
	int pos[256] = {0};
	for (int i = 0; i < 512; i++)
		exist[i] = false;
	for (int i = 0; i < 256; i++)
	{
		if(exist[s[i]*2])
		{
			if(!exist[s[i]*2+1])
				exist[s[i]*2+1] = true;
		}
		else
		{
			exist[s[i]*2] = true;
			pos[i] = s[i]; 
		}
			
	}
	for (int i = 0; i < 256; i++)
	{
		int t = 2 * pos[i];
		if(exist[t] && !exist[t+1])
		{
			printf("%c\n", pos[i]);
			break;
		}
	}
}
