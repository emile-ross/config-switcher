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

		size_t line_len = strlen(buf);
		
		for (int j = 0; line_len > j; j++)
		{
			if (buf[j] == '\t' || buf[j] == ' ')
				continue;
			if (isalpha(buf[j]))
			{
				size_t len = strcspn(buf, "<>.");
				if (configuration_type != NULL)
					free(configuration_type);


				configuration_type = malloc(len + 1);
				strncpy(configuration_type, buf, len);
				configuration_type[len] = '\0';

				printf("%s\n", configuration_type);
				i += len;
				if (len >= INT32MAX)
				{
					err(INT_OVERFLOW);
				}
				j += len;
			}
		}

		if (buf[line_len] == EOF)
		{
			return;
		}
	}
	free(buf);
}
