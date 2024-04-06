#include "monty.h"

int main(int ac, char **av)
{
	FILE *file;
	char *buffer;
	size_t n, eof, neg;

	n = 1024, neg = -1;
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
	while((eof = getline(&buffer, &n, file)) != neg)
	{
		printf("%s, %ld\n", buffer, eof);
		/*do instruction*/
	}
	/*close file & exit*/
	free(buffer);
	fclose(file);
	return(0);
}
