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
	char *switching_keyword = NULL;
	size_t switching_keyword_len = 0;

	if (!(argc > 1))
		err(ARG_NONE);
	
	for (; i < argc; i++)
	{
		if (scmp(argv[i], "--help"))
		{
			printf(
					BOLD"config-switcher [switching keyword]\n"RESET
					"The program expects a switching keyword as input.\n"
					"Specify their use in the config file located at :\n"
					"~/.config/config-switcher/config.conf \n");
			return 0;
		}
		else
		{
			switching_keyword = bmalloc(&switching_keyword_len, argv[i]);
			break;	/* only one switching_keyword can be taken as input */
		}
	}

	return 0;
}
