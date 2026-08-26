#include "header.h"

#include <string.h>

int main(int argc, char *argv[])
{
	if (!(argc > 2))
	{
		fprintf(stderr, "Missing arguments in command\n");
		return 1;
	}
	
	uint8_t i = 1;	/* ignore first argument (arg 0) */
	
	for (; i < (argc - 1); i++)
	{
		if (cmp(argv[i], "--help"))
		{
			return 0;
		}
	}

	return 0;
}

Bool cmp(char *s_one, char *s_two)
{
	if (strcmp(s_one, s_two) == 0) return True;
	else return False;
}
