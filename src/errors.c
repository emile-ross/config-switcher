#include "header.h"

#define MSG(err_msg) \
	fprintf(stderr, err_msg); \
	break;

void err(err_type error_code)
{
	Bool report = False;
	switch (error_code)
	{
	case INVALID_ERR:
		MSG("Invalid error type\n");

	case ARG_MISSING:
		MSG("The program expects more arguments after your flags\n");

	case MALLOC_FAIL:
		MSG("Failed to allocate memory (this is likely caused by a very high system memory usage)\n");

	case BUF_TRUNCATION:
		report = True;
		MSG("The string has been truncated (internal failiure)\n");
	}
	exit(1);
}
