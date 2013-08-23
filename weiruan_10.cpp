#include <stdio.h>

#define N 10


void reverseWord(char* s)
{
	int count[N];
	count[0] = 0;
	int top = 0;
	int i;
	for (i = 0; s[i] != '\0' ; ++i)
	{
		if (s[i] == ' ')
		{
			top++;
			count[top] = i+1;
		}	
	}
	top++;
	count[top] = i+1;

	
	for (i = top-1; i >= 0; --i)
	{
		for (int j = count[i]; j < count[i+1]-1; ++j)
		{
			printf("%c", s[j]);
		}
		printf(" ");
	}
	printf("\n");

}

int main()
{
	char s[256] = "I am a student.";
	reverseWord(s);
	return 0;
}