#include "header.h"

int main(int argc, char *argv[])
{
	uint8_t i = 1;	/* ignore first argument (arg 0) */

	if (!(argc > 2))
	{
		fprintf(stderr, "Missing arguments in command\n");
		return 1;
	}
	
	for (; i < (argc - 1); i++)
	{
		if (scmp(argv[i], "--help"))
		{
			printf("config-switcher [program] [file]\n");
			return 0;
		}
		else if (cmp(argv[i], "-c", "--config"))
		{
			if (i++ <= argc)
			{
				fprintf(stderr, "missing arguments\n");
				return 1;
			}
		}
		else if (cmp(argv[i], "-p", "--program"))
		{
			if (i++ <= argc)
			{
				fprintf(stderr, "missing arguments\n");
				return 1;
			}
		}
		else
		{
			/* TODO mark as an ignored option */
		}
	}

	return 0;
}
