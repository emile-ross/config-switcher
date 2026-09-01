#include "header.h"

#define NEXT_ARG() \
	if (i++ > argc) \
	{ \
		err(ARG_MISSING); \
	}

const Bool verbose = True;
const Bool testing = True;

int main(int argc, char *argv[])
{
	uint8_t i = 1;	/* ignore first argument (arg 0) */
	config_contents args = { NULL, NULL, NULL };

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
			NEXT_ARG();
			args.style_name = argv[i];
			if (verbose)
				printf("%s\n", args.style_name);
		}
		else if (cmp(argv[i], "-c", "--config"))
		{
			NEXT_ARG();
			args.config_name = argv[i];
			if (verbose)
				printf("%s\n", args.config_name);

		}
		else if (cmp(argv[i], "-p", "--program"))
		{
			/* TODO: add a -t target flag in order to 
			 * take in the target config filename (for the link) */
			NEXT_ARG();
			args.program_name = argv[i];
			if (verbose)
				printf("%s\n", args.program_name);
		}
		else
		{
			ignored_arg(argv[i]);
		}
	}

	/* check if the program name (config directory) is specified) 
	 * ( done in arg_parser() )*/

	arg_parser(&args);

	return 0;
}
