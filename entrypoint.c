#include "monty.h"

int main(int argc, char **argv)
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		file = fopen(argv[1], "r");
		if (file == NULL)
		{
			fprintf(stderr, "Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		else
		{
			/*executionj function*/
		}
	}

	/*0 or +1 = EXIT_FAILURE USAGE: monty file*/
	/*cant open file Error: Can't open file <file> EXIT_FAILURE*/
	/*file has invalid instruction L<line_number>: unknown instruction <opcode> EXIT_FAILURE*/
	/*program will stop at error in byte code*/
	/*cant malloc Error: malloc failed EXIT_FAILURE*/

}
