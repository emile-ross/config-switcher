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

	for (uint16_t i = 0; !feof(fp); i++)
	{
		if (fgets(buf, 512, fp) == NULL)
			break;

		size_t line_len = strlen(buf);
		
		for (int32_t j = 0; (signed)line_len > j; j++)
		{
			if (buf[j] == '\t' || buf[j] == ' ')
				continue;

			if (isalpha(buf[j]))
			{
				size_t len = strcspn(buf + j, "<>. ");
				if (configuration_type != NULL)
					free(configuration_type);


				configuration_type = malloc(len + 1);
				strncpy(configuration_type, buf, len);
				configuration_type[len] = '\0';

				if (buf[j] == '.')
				{
					if (scmp(configuration_type, "path"))
					{
						j++;
					}
					else if (scmp(configuration_type, "config"))
					{
						fprintf(stderr,
								"the config keyword is reserved for declaring new"
								"setup configuration/rices\nThese are used in order "
								"to group multiple configuration files together in\n"
								"a single master configuration\nDeclare a new "
								"configuration using: \"config [name]\"\n");
					}
				}

				if (len >= INT32MAX)
				{
					err(INT_OVERFLOW);
				}
				j += (int32_t)len;
			}
		}

		if (buf[line_len] == EOF)
		{
			return;
		}
	}
	free(buf);
}
