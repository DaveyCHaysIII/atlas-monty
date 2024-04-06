#include "monty.h"

/**
 * san_buffer()- sanitizes buffer
 * @buff: the source buffer
 *
 * Return: no return
 */

void san_buffer(char *buff)
{
	int i, j;

	i = 0;
	j = 0;

	while (buff[i] != '\0')
	{
		if (isspace(buff[i]))
		{
			if (buff[i] == '\n' || buff[i] == '$')
			{
				buff[i] = '\0';
			}
			i++;
			continue;
		}
		else if (isspace(buff[j]))
		{
			if (isdigit(buff[i + 1]))
			{
				buff[j] = ' ';
				j++;
			}
			buff[j] = buff[i];
			buff[i] = '\0';
			j++;
		}
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
