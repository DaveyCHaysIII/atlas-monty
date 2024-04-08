#include "monty.h"

void pint(stack_t **stack, char **arg, unsigned int l)
{
	(void)arg;

	if(!(*stack))
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", l);
		free_stack(stack);
		fclose(fd);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

void pop(stack_t **stack, char **arg, unsigned int l)
{
	stack_t *current;
	stack_t *tmp;

	if(!(*stack))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", l);
		free_stack(stack);
		fclose(fd);
		exit(EXIT_FAILURE);
	}

	(void)arg;
	current = *stack;
	tmp = current->next;
	tmp->prev = NULL;
	*stack = current->next;;
	free(current);
}

void nop(stack_t **stack, char **arg, unsigned int l)
{
	(void)stack;
	(void)arg;
	(void)l;
}
