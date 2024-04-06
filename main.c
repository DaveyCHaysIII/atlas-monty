#include "monty.h"

int main(int ac, char **av)
{
	/*arg check*/
	if (ac < 2)
	{
		fprintf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/*open the file*/
	file = fopen(av[1], "r");
	if (file == NULL)
	{
		fprintf("Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	/*main loop*/
	while(/*getline != -1*/)
	{
		/*do instructions*/
	}
	/*close file & exit*/
	fclose(file)
	return(0);
}
