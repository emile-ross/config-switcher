#include "header.h"

#include "table.h"

char *get_config_name(const char *restrict program_name, Bool *success, enum config_switch_type export_type)
{
	*(success) = True;

	/* get the total number of configs (in the program) */
	uint16_t num_configs = sizeof(program_configs) / sizeof(program_configs[0]);

	for (uint16_t i = 0; i < num_configs; i++)
	{
		if (scmp(program_name, (program_configs[i]).program_name))
		{

			if (export_type == config)
			{
				*(success) = True;
				return program_configs[i].config_name;
			}
			else if (export_type == style)
			{
				*(success) = True;
				return program_configs[i].style_name;
			}
			else
			{
				*(success) = False;
				fprintf(stderr, "Unknown config type in config_match.c\n");
				break;
			}
		}
	}

	/* defaults to 'config' for the configuration name */
	*(success) = False;
	return "config";
}

