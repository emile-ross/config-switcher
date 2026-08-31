#include "header.h"

#include <string.h>

Bool cmp(const char *restrict arg, const char *restrict s_one, const char *restrict s_two)
{
	if (strcmp(arg, s_one) == 0) return True;
	else if (strcmp(arg, s_two) == 0) return True;
	else return False;
}

Bool scmp(const char *restrict arg, const char *restrict s)
{
	if (strcmp(arg, s) == 0) return True;
	else return False;
}
