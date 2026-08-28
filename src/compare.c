#include "header.h"

#include <string.h>

Bool cmp(char *arg, const char *s_one, const char *s_two)
{
	if (strcmp(arg, s_one) == 0) return True;
	else if (strcmp(arg, s_two) == 0) return True;
	else return False;
}

Bool scmp(char *arg, char *s)
{
	if (strcmp(arg, s) == 0) return True;
	else return False;
}
