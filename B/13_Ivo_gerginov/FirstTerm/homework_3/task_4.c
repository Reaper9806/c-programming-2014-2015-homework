#include <stdio.h>

int main()
{
	int fact,i,n,m;
	fact=1;
	for(n=10;n>0;n--)
	{
		fact=fact*n;
	}
	printf("!10 = %d\n",fact);
	return 0;
}
