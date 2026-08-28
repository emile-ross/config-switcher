#include "header.h"

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
	}
	exit(1);
}
