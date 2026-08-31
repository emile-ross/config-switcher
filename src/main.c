#include "header.h"

const Bool verbose = True;

int main(int argc, char *argv[])
{
	uint8_t i = 1;	/* ignore first argument (arg 0) */
	command_args args = { NULL, NULL, NULL };

	if (!(argc > 2))
		err(ARG_NONE);
	
	for (; i < (argc - 1); i++)
	{
		if (scmp(argv[i], "--help"))
		{
			printf("config-switcher [program] [file]\n");
			return 0;
		}
		else if (cmp(argv[i], "-s", "--style"))
		{
			if (i++ > argc)
				err(ARG_MISSING);
			args.style_name = argv[i];
			if (verbose)
				printf("%s\n", args.style_name);
		}
		else if (cmp(argv[i], "-c", "--config"))
		{
			if (i++ > argc)
				err(ARG_MISSING);
			args.config_name = argv[i];
			if (verbose)
				printf("%s\n", args.config_name);

		}
		else if (cmp(argv[i], "-p", "--program"))
		{
			if (i++ > argc)
				err(ARG_MISSING);
			args.program_name = argv[i];
			if (verbose)
				printf("%s\n", args.program_name);
		}
		else
		{
			fprintf(stderr, "Ignored arg: %s\n", argv[i]);
			fprintf(stderr, "You can view valid arguments using the --help flag\n");
			return 1;
		}
	}
	return 0;
}
