#include "monty.h"

void push(stack_t **stack, unsigned int l);
void pall(stack_t **stack, unsigned int l);

/**
 * getopfunc()- gets a pointer to the operation!
 * @s: the op to compare to!
 * @stack: the stack!
 * @l: the line count!
 */

void (*getopfunc(char *s))(stack_t **stack, unsigned int l)
{
	int i;

	instruction_t ops[] = {

		{"push", push},
		{"pall", pall},
		/*{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},*/
		{NULL, NULL}
	};

	i = 0;
	while (ops[i].opcode != NULL)
	{
		if (strcmp(s, ops[i].opcode) == 0)
			return (ops[i].f);
		i++;	
	}
	fprintf(stderr, "Op %s not found at line ", s);  
	return (NULL);
}

void push(stack_t **stack, unsigned int l)
{
	(void)stack;
	printf("called push for line number %u\n", l);
}

void pall(stack_t **stack, unsigned int l)
{
	(void)stack;
 	printf("called push for line number %u\n", l);

}
