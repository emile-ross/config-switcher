#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>


#define ANSI_RED	"\x1b[31m"
#define STYLE_END	"\x1B[0m" 

void warn(const char *restrict fmt, ...)
{
	va_list args, copy;
	va_start(args, fmt);
	va_copy(copy, args);

	/* get the string length using vsnprintf() */
	unsigned int size = 1 + (unsigned)vsnprintf(NULL, 0, fmt, copy);
	va_end(copy);

	/* allocate memory for the string */
	char *str = malloc(size);
	int ret = snprintf(str, size, fmt, args);

	if (ret > (signed)size)
	{
		fprintf(stderr, ANSI_RED"Truncated warning message\n"STYLE_END);
	}

	printf("\x1b[31m%s\n\x1b[0m", str);
}
