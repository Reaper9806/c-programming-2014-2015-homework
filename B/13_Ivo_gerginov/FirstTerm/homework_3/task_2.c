#include <stdio.h>

int main()
{
	unsigned long long i,m=2,n=1;
	int x;
	printf("%llu - 1\n%llu - 2\n",m,n);
	/*numbers from around 93 and above are wrong
	need help!!!*/
	for(x=3;x<=100;x++)
	{	
		i=n+m;
		printf("%llu ,",i,x);
		m=n;n=i;
	}
	return 0;
}
