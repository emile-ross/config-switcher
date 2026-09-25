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
	char *switching_word = NULL;

	if (!(argc > 1))
		err(ARG_NONE);
	
	for (; i < argc; i++)
	{
		if (scmp(argv[i], "--help"))
		{
			printf("config-switcher [switching keyword]\n");
			return 0;
		}
		else if (argv[i][0] == '-')
		{
			ignored_arg(argv[i]);
		}
		else
		{
			switching_word = bmalloc(argv[i]);
			break;	/* only one switching_word can be taken as input */
		}
	}

	return 0;
}
