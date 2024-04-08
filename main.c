#include "monty.h"

FILE *fd = NULL;

/**
 * main()- the entry to the file!
 * @ac: number of args passed
 * @av: argument vector
 *
 * Return: 0 on success
 */

int main(int ac, char **av)
{
	char *buffer;
	char **tokens;
	size_t n, linenum;
	ssize_t neg;
	int status;
	stack_t *stack = NULL;

	n = 0, status = 0; neg = -1, linenum = 1, buffer = NULL;
	tokens = malloc(sizeof(char *) * 100);
	/*arg check*/
	if (ac < 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/*open the file*/
	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	/*main loop*/
	while ((getline(&buffer, &n, fd)) != neg)
	{
		if(empty(buffer) < 0)
		{
			continue;
		}
		tokenize(tokens, buffer);
		getopfunc(&stack, tokens, linenum)(&stack, tokens, linenum);
		free_tokens(tokens);
		linenum++;
	}
	/*close file & exit*/
	free(buffer);
	free(tokens);
	free_stack(&stack);
	fclose(fd);
	if (status < 0)
	{
		exit(EXIT_FAILURE);
	}
	return (0);
}

/**
 * tokenize()- tokenizes buffer
 * @tokens: the token bucket
 * @buffer: the buffer we're reading from
 *
 * Return: no return
 */

void tokenize(char **tokens, char *buffer)
{
	char *token;
	int i;

	san_buffer(buffer);
	token = strtok(buffer, " \t\n$");
	i = 0;
	while (token != NULL)
	{
		tokens[i] = malloc(strlen(token) + 1);
		if (tokens[i] == NULL)
		{
			printf("Token failed!");
			fprintf(stderr, "Could not allocate memory for token");
			free_tokens(tokens);
		}
		strcpy(tokens[i], token);
		token = strtok(NULL, " ");
		i++;
	}
	tokens[i] = NULL;
}

/**
 * free_tokens()- frees token array
 * @tokens: the array of tokens to free
 *
 * Return: no return
 */

void free_tokens(char **tokens)
{
	int i;

	i = 0;
	while (tokens[i] != NULL)
	{
		free(tokens[i]);
		tokens[i] = NULL;
		i++;
	}
}

int empty(char *buffer)
{
	int i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (isalnum(buffer[i]))
		{
			return (1);
		}
		i++;
	}
	return (-1);
}
