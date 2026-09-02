#include "header.h"

#define MSG(err_msg) \
	fprintf(stderr, "error: %s", err_msg); \
	break;

void err(err_type error_code)
{
	Bool report = False;

	switch (error_code)
	{
	case INVALID_ERR:
		MSG("Invalid error type\n");

	case ARG_NONE:
		MSG("The program requires at least 1 additional argument\n");

	case ARG_MISSING:
		MSG("The program expects more arguments after your flags\n");

	case MISSING_INPUT_FILES:
		MSG("The program needs input file paths in order to work\n");

	case MALLOC_FAIL:
		MSG("Failed to allocate memory (this is likely caused by a very high system memory usage)\n");

	case LSTAT_FAIL:
		MSG("lstat() failed\n");

	case INVALID_ARGS:
		report = True;
		MSG("The arguments are missing in the arg_parser() function\n");

	case BUF_TRUNCATION:
		report = True;
		MSG("The string has been truncated (internal failure)\n");

	default:
		report = True;
		MSG("Invalid error message");
	}

	if (report)
		fprintf(stderr, "Please report this issue on github at "
				UDRL_S"https://github.com/emile-ross/config-switcher/issues/\n"STYLE_END);
	exit(1);
}

void ignored_arg(char *flag)
{
	fprintf(stderr, ANSI_RED BOLD_S"Ignored arg: %s\n"STYLE_END, flag);
	fprintf(stderr, ANSI_RED BOLD_S"You can view valid arguments using the --help flag\n"STYLE_END);
}
