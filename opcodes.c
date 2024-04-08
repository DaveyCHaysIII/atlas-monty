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

void swap(stack_t **stack, char **arg, unsigned int l)
{
	int nodecount, temp;
	stack_t *current;

	(void)arg;
	temp = (*stack)->n;
	nodecount = 0;
	current = *stack;
	while (current != NULL)
	{
		nodecount++;
		current = current->next;
	}
	if (nodecount < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", l);
		free_stack(stack);
		fclose(fd);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	current->n = (current->next)->n;
	(current->next)->n = temp;

}

void add(stack_t **stack, char **arg, unsigned int l)
{
	int nodecount, val;
	stack_t *current;
	stack_t *tmp;

	(void)arg;
	nodecount = 0;
	current = *stack;
	tmp = current->next;
	while (current != NULL)
	{
		nodecount++;
		current = current->next;
	}
	if (nodecount < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", l);
		free_stack(stack);
		fclose(fd);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	val = current->n;
	tmp->n += val;
	tmp ->prev = NULL;
	(*stack) = tmp;
	free(current);
}

void nop(stack_t **stack, char **arg, unsigned int l)
{
	(void)stack;
	(void)arg;
	(void)l;
}


