#include<stdio.h>
#include<string.h>
# define NO_OF_CHARS 256
void search(char*,char*);
int max(int,int);
char str[200];
char ptr[150];
int s,p,j;
int max(int a, int b)
{
	return (a > b)? a: b;
} 
void badChar(char *ptr, int size,int badchar[NO_OF_CHARS]) 
{ 
    int i; 
    for (i = 0; i < NO_OF_CHARS; i++) 
    {
    	badchar[i] = -1;
	}
    for (i = 0; i < size; i++) 
    {
    	badchar[(int) ptr[i]] = i;	
	}
} 
void search(char* str,char* ptr)
{
	int x=0;
	int badchar[NO_OF_CHARS];
    badChar(ptr, p, badchar);
	while(x<=(s-p))
	{
		j=p-1;
		while(j>=0 && ptr[j]==str[x+j])
		{
			j--;
		}	
		if(j<0)
		{
			printf("Pattern is found at: %d index.\n",x);
			x+= (x+p < s)? p-badchar[str[x+p]] : 1;
		}
		else
		{
			x+= max(1, j - badchar[str[x+j]]); 
		}
	}
}
int main()
{
	printf("Enter the string.\n");
	scanf("%s",str);
	printf("Enter the pattern.\n");
	scanf("%s",ptr);
	s=strlen(str);
	p=strlen(ptr);
	if(p<=s)
	{
		search(str,ptr);
	}
	else
	{
		printf("Pattern matching cant't be perfomed.\n");
	}
}
