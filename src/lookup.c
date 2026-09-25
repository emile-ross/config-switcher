#include "header.h"

#include <ctype.h>
#include <string.h>

void lookup_keyword(char *switching_keyword)
{
	FILE *fp = fopen("config.conf", "r");
	if (fp == NULL)
		err(NO_SUCH_FILE);
	char *buf = malloc(512);
	if (buf == NULL)
		err(MALLOC_FAIL);

	char *configuration_type = NULL;
	for (uint16_t i = 0; i < 100; i++)
	{
		if (fgets(buf, 512, fp) == NULL)
			break;
		}
	}
	free(buf);
}
