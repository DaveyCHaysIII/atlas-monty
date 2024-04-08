#include "monty.h"

/**
 * getopfunc()- gets a pointer to the operation!
 * @s: the op to compare to!
 * @stack: the stack!
 * @l: the line count!
 */

void (*getopfunc(stack_t **stack, char **args, unsigned int l))(stack_t **stack, char **args, unsigned int l)
{
	int i;

	instruction_t ops[] = {

		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		/*{"swap", swap},
		{"add", add},
		{"nop", nop},*/
		{NULL, NULL}
	};

	i = 0;
	while (ops[i].opcode != NULL)
	{
		if (strcmp(args[0], ops[i].opcode) == 0)
			return (ops[i].f);
		i++;	
	}
	fprintf(stderr, "Op %s not found at line %u\n", args[0], l);
	free_stack(stack);
	free_tokens(args);
	free(args);
	fclose(fd);
	exit(EXIT_FAILURE);
}

void push(stack_t **stack, char **args, unsigned int l)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	stack_t *tmp;

	if (!args[1])
	{
		fprintf(stderr, "L%u: usage: push integer\n", l);
		free_stack(stack);
		free_tokens(args);
		free(args);
		fclose(fd);
		exit(EXIT_FAILURE);
	}
	if (new_node == NULL)
	{
		fprintf(stderr, "error- memalloc");
	}
	if (*stack)
	{
		tmp = *stack;
		tmp->prev = new_node;
	}
	new_node->n = atoi(args[1]);
	new_node->next = *stack;
	new_node->prev = NULL;
	*stack = new_node;
}

void pall(stack_t **stack, char **args, unsigned int l)
{
	size_t  nodecount;
	stack_t *current = *stack;

	(void)args;
	(void)l;
	nodecount = 0;
	while (current != NULL)
	{
		printf("%d\n",current->n);
		current = current->next;
		nodecount++;
	}
}

void free_stack(stack_t **stack)
{
	stack_t *current = *stack;
	
	while (current != NULL)
	{
		stack_t *next = current->next;
		free(current);
		current = next;
	}
}

