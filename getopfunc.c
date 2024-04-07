#include "monty.h"

/**
 * getopfunc()- gets a pointer to the operation!
 * @s: the op to compare to!
 * @stack: the stack!
 * @l: the line count!
 */

void (*getopfunc(char *s))(stack_t **stack, unsigned int l)
{
	int i;

	intstruct_t ops[] = {

		{"push", push},
		{"pall", pall},
		/*{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},*/
		{NULL, NULL};
	};

	i = 0;
	while (ops[i] != NULL)
	{
		if (strcmp(*s, ops[i].instrcut_s[0]) == 0)
			return (ops[i].f);
		i++;	
	}
	fprintf(stderr, "Op %s not found at line %ld", s, l);  
	return (NULL);
}
