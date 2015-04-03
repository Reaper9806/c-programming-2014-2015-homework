#include <stdio.h>
 
int main()
{
	int num; 
	int reverse=0; 
	printf("Enter a number to reverse\n");
	scanf("%d",&num);
 	while (num!=0)
   	{
      		reverse=reverse*10;
      		reverse=reverse+num%10;
      		num=num/10;
   	}
   	printf("Reverse of entered number is = %d\n",reverse);
   	return 0;
}
