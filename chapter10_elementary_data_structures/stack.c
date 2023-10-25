#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <errno.h>

typedef struct
{
	uint8_t top;
	uint8_t size;
	uint8_t array[];
} stack;

bool isempty(stack *s)
{
	if (s->top == 0)
	{
		return true;
	}

	return false;
}

void push(stack *s, uint8_t value)
{
	if (s->size != 0 && s->top == s->size)
	{
		// error overflow
		perror("overflow");
	}
	else
	{
		s->top = s->top + 1;

		s->array[s->top - 1] = value;
	}
}

uint8_t pop(stack *s)
{

	if (isempty(s))
	{
		// error overflow
		perror("overflow");
	}
	else
	{
		s->top = s->top - 1;
		return s->array[s->top];
	}
}

void main()
{
	stack *s;

	s = malloc(sizeof(stack));

	push(s, 10);
	push(s, 15);
	push(s, 20);
	push(s, 25);

	for (int i = 0; i < s->top; i++)
	{
		printf("index: %d | value: %d\n", i, s->array[i]);
	}

	pop(s);

	for (int i = 0; i < s->top; i++)
	{
		printf("index: %d | value: %d\n", i, s->array[i]);
	}

	pop(s);
	pop(s);
	pop(s);
	pop(s);
}
