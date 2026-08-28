#include "header.h"
#include <stdarg.h>

char *bmalloc(char *fmt, ...)
{
	/* args copy is used for getting the string length *
	 * args is for creating the final string */
	va_list args_copy, args; 
	size_t str_len = 0;	/* store the initial str len for allocating memory */
	int ret = 0;	/* store the return value of the string length */
	va_start(args, fmt);
	va_copy(args_copy, args);

	str_len = (size_t)vsnprintf(NULL, 0, fmt, args_copy);
	va_end(args_copy);

	char *str = malloc(str_len);

	ret = vsnprintf(str, str_len, fmt, args);
	va_end(args);
	
	return str;
}
