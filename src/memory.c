#include "header.h"

#include <stdarg.h>

char *bmalloc(const char *restrict fmt, ...)
{
	/* args copy is used for getting the string length *
	 * args is for creating the final string */
	va_list args_copy, args; 
	va_start(args, fmt);
	va_copy(args_copy, args);

	/* store the initial str len for allocating memory */
	size_t str_len = 1 + (size_t)vsnprintf(NULL, 0, fmt, args_copy);
	va_end(args_copy);

	char *str = malloc(str_len);
	/* check for malloc() failure*/
	if (str == NULL)
	{
		err(MALLOC_FAIL);	/* should exit */
		return NULL;
	}

	/* store the return value of the string length in 'ret' */
	int ret = vsnprintf(str, str_len, fmt, args);
	va_end(args);
	if ((unsigned)ret > str_len)
	{
		err(BUF_TRUNCATION);
		return NULL;
	}
	
	return str;
}
