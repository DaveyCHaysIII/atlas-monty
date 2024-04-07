#include "monty.h"

/**
 * san_buffer()- sanitizes buffer
 * @buff: the source buffer
 *
 * Return: no return
 */

void san_buffer(char *buff)
{
	int i;

	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
			buff[i] = '\0';
		if (buff[i] == '$')
			buff[i] = '\0';
		i++;
	}
}

/**
 * clear_buffer()- clears a buffer!
 * @buffer: the buffer that needs clearing
 *
 * Return: no return
 */

void clean_buffer(char *buffer)
{
	int len, i;

	len = strlen(buffer);
	for (i = 0; i < len; i++)
	{
		if (buffer[i] != '\0')
		{
			buffer[i] = '\0';
		}
	}
}

void print_tokens(char **tokens)
{
	int i;

	i = 0;
	while (tokens[i] != NULL)
	{
		printf("%s\n", tokens[i]);
		i++;
	}		
}

int is_opcode(const char *token)
{
	if (token != NULL)
	{
		if (strstr(token, "pall") != NULL)
			return 0;
		else if (strstr(token, "push") != NULL)
			return 1;
		else if (strstr(token, "pint") != NULL)
			return 2;
		else if (strstr(token, "pop") != NULL)
			return 3;
		else if (strstr(token, "swap") != NULL)
			return 4;
		else if (strstr(token, "add") != NULL)
			return 5;
		else if (strstr(token, "nop") != NULL)
			return 6;
		else
			return -1;
	}
	return -1;
}
