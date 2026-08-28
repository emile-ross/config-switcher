#include "header.h"

#define MSG(err_msg) \
	fprintf(stderr, err_msg); \
	break;

void err(err_type error_code)
{
	switch (error_code)
	{
	case INVALID_ERR:
		fprintf(stderr, "Invalid error type\n");
		break;

	case ARG_MISSING:
		fprintf(stderr, "The program expects more arguments after your flags\n");
		break;

	case MALLOC_FAIL:
		fprintf(stderr, "Failed to allocate memory (this is likely caused by a very high system memory usage)\n");
		break;
	case BUF_TRUNCATION:
		fprintf(stderr, "The string has been truncated (internal failiure)\n");
		break;
	}
	exit(1);
}
