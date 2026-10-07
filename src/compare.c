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
	for (uint32_t i = 0; 1 ; i++)
	{
		if (arg[i] == '\0' || s[i] == '\0')
		{
			if (arg[i] == '\0' && s[i] == '\0')
			{
				return True;
			}
			return False;
		}

		if (arg[i] != s[i])
		{
			return False;
		}
	}
	return True;
}
