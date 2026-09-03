#include <stdio.h>
#include <stdarg.h>

void warn(const char *restrict fmt, ...)
{
	va_list args, copy;
	va_start(args, fmt);
	va_copy(copy, args);
	unsigned int size = (unsigned)vsnprintf(NULL, 0, fmt, copy);
	va_end(copy);
}
