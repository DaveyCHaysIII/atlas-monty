#include "monty.h"

void push(stack_t **stack, char **args, unsigned int l);
void pall(stack_t **stack, char **args, unsigned int l);

/**
 * getopfunc()- gets a pointer to the operation!
 * @s: the op to compare to!
 * @stack: the stack!
 * @l: the line count!
 */

void (*getopfunc(char *s))(stack_t **stack, char **args, unsigned int l)
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

void push(stack_t **stack, char **args, unsigned int l)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	stack_t *tmp;

	if (!args[1])
	{
		fprintf(stderr, "L%u: usage: push integer\n", l);
		exit(EXIT_FAILURE);
	}
	if (new_node == NULL)
	{
		fprintf(stderr, "error- memalloc");
	}
	if (*stack != NULL)
	{
		printf("Stack is NOT null");
		tmp = *stack;
		tmp->prev = new_node;
	}
	new_node->n = atoi(args[1]);
	printf("%d\n", new_node->n);
	new_node->next = *stack;
	new_node->prev = NULL;
	*stack = new_node;
}

void pall(stack_t **stack, char **args, unsigned int l)
{
	(void)stack;
	(void)*args;
 	printf("called push for line number %u\n", l);
}
