#include "monty.h"

void pint(stack_t **stack, char **arg, unsigned int l)
{
	(void)arg;

	if(!(*stack))
	{
		fprintf(stderr, "L%u: can't pint, stack empty", l);
		free_stack(stack);
		fclose(fd);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
