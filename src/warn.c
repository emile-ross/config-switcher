#include <stdio.h>
#include <stdarg.h>

void warn(const char *restrict fmt, ...)
{
	va_list args, copy;
	va_start(args, fmt);
	va_copy(copy, args);
	/* get the string length using vsnprintf() */
	unsigned int size = (unsigned)vsnprintf(NULL, 0, fmt, copy);
	va_end(copy);

	/* allocate memory for the string */
	char *str = malloc(size);
	int ret = snprintf(str, size, fmt, args);

}


