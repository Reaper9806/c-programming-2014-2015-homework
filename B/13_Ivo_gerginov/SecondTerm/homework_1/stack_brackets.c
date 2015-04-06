#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define INIT_SIZE 4

struct stack_t{

	int size, top;
	char *data;
};

void init(struct stack_t *s)
{
	s->size = INIT_SIZE;
	s->top = 0;
	s->data = (char*)malloc(s->size * sizeof(char));
}

void destr(struct stack_t *s)
{
	s->size = 0;
	s->top = 0;
	free(s->data);
}

int get_size(struct stack_t s)
{
	return s.size;
}

void data_trans(char *old, int old_size, char *new)
{
	int i;
	for(i = 0; i < old_size; i++)
		new[i] = old[i];
}

int resize(struct stack_t *s)
{
	char *new_data = (char*)malloc(s->size * sizeof(char));

	data_trans(s->data, s->size, new_data);

	free(s->data);
	s->data = new_data;

	if(s->data == NULL)
		return -1;

	return 0;
}

int size_incr(struct stack_t *s)
{
	s->size *= 2;
	if (resize(s) == -1)
		return -1;

	return 0;
}

int size_decr(struct stack_t *s)
{
	s->size /= 2;
	if (resize(s) == -1)
		return -1;

	return 0;
}

void push(struct stack_t *s, char value) {
	if (s->top == s->size)
		size_incr(s);

	s->data[s->top] = value;
}

int pop(struct stack_t* s) {
	if(s->top == 0)
		return INT_MIN;

	if(s->top <= s->size / 2 && s->size > INIT_SIZE)
		size_decr(s);

	return s->data[--s->top];
}

int main()
{
	struct stack_t brackets;
	init(&brackets);
	char brac_str[50];
	int cntr, max; 

	printf("Enter brackets expression:\n");
	scanf("%s", brac_str);
	max = strlen(brac_str);

	for(cntr = 0;cntr < max;cntr++)
	{
		switch (brac_str[cntr])
		{
			case '{':
			case '[':
			case '(':
			{
				if(cntr == max - 1)
				{
					printf("Invalid expression!!! Cannot end with opening bracket!\n");
					break;
				}
				else push(&brackets, brac_str[cntr]);
				break;
			}
			case '}':
			{
				if(cntr == 0)
				{
					printf("Invalid expression!!! Cannot start with closing bracket!\n");
					break;
				}
				else
				{
					if(brackets.data[brackets.top] != '{')
						
							
							{
								printf("Invalid expression!!!\n");
								break;
							}
					else
					{ 
						pop(&brackets);
						if (cntr == max - 1)
							printf("Expression is valid.\n");
					}
				}
				break;
			}
			case ')':
			{	
				if(cntr == 0)
				{
					printf("Invalid expression!!! Cannot start with closing bracket!\n");
					break;
				}
				else 
				{
					if(brackets.data[brackets.top] != '(')
					{
						printf("Invalid expression!!!\n");
						break;
					}
					else
					{ 
						pop(&brackets);
						if (cntr == max - 1)
							printf("Expression is valid.\n");
					}
				}
				break;
			}
			case ']':
			{
				if(cntr == 0)
				{
					printf("Invalid expression!!! Cannot start with closing bracket!\n");
					break;
				}
				else 
				{
					if(brackets.data[brackets.top] != '[')
					{
						printf("Invalid expression!!!\n");
						break;
					}
					else
					{ 
						pop(&brackets);
						if (cntr == max - 1)
							printf("Expression is valid.\n");
					}
				}
				break;
			}
		}
	}
	return 0;
}
