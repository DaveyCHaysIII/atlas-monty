#include "monty.h"

int main(int ac, char **av)
{
	FILE *file;
	char *buffer;
	size_t n;  
	ssize_t neg;

	n = 1024, neg = -1;
	buffer = NULL;
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
		san_buffer(buffer);
		printf("%s\n", buffer);
		/*do instruction*/
	}
	/*close file & exit*/
	free(buffer);
	fclose(file);
	return(0);
}
