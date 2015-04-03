#include <stdio.h>

int main()
{
	int size;
	for (size=1;size<= 11;size++)
	{
		switch(size)
		{
			case 4:
				growTree(4);
				break;
			case 7:
				growTree(7);
				break;
			case 11:
				growTree(11);
				break;
			break;
		}
	}
return 0;
}


int growTree(int lines)
{
	int counter1;
	int blank;
	int counter2 = 0;
	for(counter1=1;counter1<=lines;counter1++)
	{
			for(blank=1;blank<=lines-counter1;blank++)
			{
				printf(" ");
			}
			do
			{
				printf("*");
				counter2++;
			}	
			while(counter2< 2*counter1 - 1);
			counter2=0;
			printf(" \n");			
	}
	

}

