#include "header.h"

int main(int argc, char *argv[])
{
	uint8_t i = 1;	/* ignore first argument (arg 0) */
	command_args args = { NULL, NULL };

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
			if (i++ > argc)
				err(ARG_MISSING);
			args.config_name = argv[i];
			printf("%s\n", args.config_name);

		}
		else if (cmp(argv[i], "-p", "--program"))
		{
			if (i++ > argc)
				err(ARG_MISSING);
			args.program_name = argv[i];
			printf("%s\n", args.program_name);
		}
		else
		{
			/* TODO mark as an ignored option */
		}
	}

	return 0;
}
