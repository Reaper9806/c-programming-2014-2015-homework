#include <stdio.h>

int main()
{
	int prim;
	for(prim=0;prim<30000;prim++)
	{
		if(prim%2!=0 && (prim%3==0 && prim%7==0))
		{
			printf("%d\n",prim);
		}
	}
	return 0;
}
