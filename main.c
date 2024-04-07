#include "monty.h"

int is_opcode(char *token);

int main(int ac, char **av)
{
	FILE *file;
	char *buffer;
	char **tokens;
	size_t n, linenum;
	ssize_t neg;

	n = 0, neg = -1, linenum = 1, buffer = NULL;
	tokens = malloc(sizeof(char*) * 100);
	/*arg check*/
	if (ac < 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/*open the file*/
	file = fopen(av[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	/*main loop*/
	while((getline(&buffer, &n, file)) != neg)
	{
		tokenize(tokens, buffer);
		print_tokens(tokens);
		/*do the function pointer call*/
		free_tokens(tokens);
		linenum++;
	}
	/*close file & exit*/
	free(buffer);
	free_tokens(tokens);
	free(tokens);
	fclose(file);
	return(0);
}

void tokenize(char **tokens, char *buffer)
{
	char *token;
	int i;

	san_buffer(buffer);
	token = strtok(buffer, " ");
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
