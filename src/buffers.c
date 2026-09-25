#include "header.h"

char *get_next_word(char *buffer, int64_t index, const char *restrict reject)
{
	int64_t end = strcspn(buffer, reject);
}
