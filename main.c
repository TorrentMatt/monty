#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};
/**
* main - code interpreter
* @argc: arguments
* @argv:  file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	/*size_t size = 0;*/
	ssize_t readline = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can not open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (readline > 0)
	{
		content = NULL;
		readline = getline(&content, &size, file);
		bus.content = content;
		counter++;
		if (readline > 0)
		{
			execute(content, &stack, counter, file);
		}
		free(content);
	}
	free_stack(stack);
	fclose(file);
return (0);
}
