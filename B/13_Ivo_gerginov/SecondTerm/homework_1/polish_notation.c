#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define INIT_SIZE 4

struct stack_t
{
	int size, top;
	int *data;
};

void init(struct stack_t *s)
{
	s->size = INIT_SIZE;
	s->top = 0;
	s->data = (int*)malloc(s->size * sizeof(int));
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

void data_trans(int *old, int old_size, int *new)
{
	int i;
	for(i = 0; i < old_size; i++)
		new[i] = old[i];
}

int resize(struct stack_t *s)
{
	int *new_data = (int*)malloc(s->size * sizeof(int));
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

void push(struct stack_t *s, int value)
{
	if (s->top == s->size)
		size_incr(s);
	s->data[s->top] = value;
}

int pop(struct stack_t* s) 
{
	if(s->top == 0)
		return INT_MIN;

	if(s->top <= s->size / 2 && s->size > INIT_SIZE)
		size_decr(s);

	return s->data[--s->top];
}

/*
За проверката и калкулацията на израза в полски запис имам 2 варианта - с if-ове и switch.
По някаква причина заради проверката брояча на for- цикъла цикли само м/у 0 и -1 вместо
от 0 до strl(дължината на израза). В нито един от двата вариянта не променям cntr(брояча)
по никакъв начин и не знам каде ми е грешката
*/

int main()
{
	struct stack_t nums;
	char expr[50];
	int cntr, strl = 0;
	float pop_num1 = 0, pop_num2 = 0;
	int pushed_num = 0;
	float ans = 0;

	init(&nums);
	printf("Your expression here:\n");	
	scanf("%[^\n]", expr);

	strl = strlen(expr);
	printf("%d\n", strl);
	for (cntr = 0; cntr < strl; cntr++)
	{
		
		switch (expr[cntr])
		{
			case 48 ... 57:
			{
				pushed_num *= 10;
				pushed_num += (expr[cntr] - 48);
				break;
			}
			case ' ':
			{
				if(expr[--cntr] >= 48 && expr[--cntr] <= 57)
					push(&nums, pushed_num);
				break;
			}
			case '*'||'/'||'+'||'-':
			{
				pop_num1 = (float)pop(&nums);
				pop_num2 = (float)pop(&nums);
				if(expr[cntr] == '+')
					ans = pop_num1 + pop_num2;
				else if(expr[cntr] == '-')
					ans = pop_num1 - pop_num2;
				else if(expr[cntr] == '*')
					ans = pop_num1 * pop_num2;
				else if(expr[cntr] == '/')
					ans = pop_num1 / pop_num2; 
				push(&nums, ans);
				break;
			}
		}
		/*if (cntr == strl) break;
		if(expr[cntr] >= '0' && expr[cntr] <= '9')
		{
			pushed_num *= 10;
			pushed_num += (expr[cntr] - 48);
		} 
		else if (expr[cntr] == ' ')
		{
			if(expr[--cntr] >= '0' && expr[--cntr] <= '9')
					push(&nums, pushed_num);		
		}
		else if(expr[cntr] == '*'||'/'||'+'||'-')
		{
				pop_num1 = (float)pop(&nums);
				pop_num2 = (float)pop(&nums);
				if(expr[cntr] == '+')
					ans = pop_num1 + pop_num2;
				else if(expr[cntr] == '-')
					ans = pop_num1 - pop_num2;
				else if(expr[cntr] == '*')
					ans = pop_num1 * pop_num2;
				else if(expr[cntr] == '/')
					ans = pop_num1 / pop_num2;
				printf("%.2f\n ans of operator", ans); 
				push(&nums, ans);
		}*/
	}
	ans = nums.data[nums.top];
	printf("%.2f\n", ans);
	return 0;
}

