#include "header.h"

#include "table.h"

char *get_config_name(const char *restrict program_name, Bool *success, enum config_switch_type export_type)
{
	*(success) = True;

	/* get the total number of configs (in the program) */
	uint16_t num_configs = sizeof(program_configs) / sizeof(program_configs[0]);

	if (export_type == config)
	{
		for (uint16_t i = 0; i < num_configs; i++)
		{
			if (scmp(program_name, (program_configs[i]).program_name))
			{
				*(success) = True;
				/* TODO make use of the style name 
				 * the program currently defaults to style.css */
				return program_configs[i].config_name;
			}
		}
	}

	/* defaults to 'config' for the configuration name */
	*(success) = False;
	return "config";
}

