#include "header.h"

void arg_parser(arg_config_contents *args, enum config_switch_type export_type)
{
	if (args->program_name == NULL)
		err(INVALID_ARGS);

	const char *home = getenv("HOME");

	char *src_fp = NULL;
	char *path_template = "%s/%s/%s/%s";

	if (args->src_filename != NULL)
	{
		src_fp = bmalloc(path_template, home, path_to_config, args->program_name, args->src_filename);
	}
	else
		err(INVALID_ARGS);

	char *dst_filename = NULL;

	if (args->dst_filename != NULL)
	{
		/* target flag is specified */
		dst_filename = args->dst_filename;
	}
	else
	{
		if (export_type == style)
		{
			dst_filename = bmalloc("style.css");	/* defaults to style.css for the style name */
		}
		else if (export_type == config)
		{
			Bool success = False;
			dst_filename = bmalloc(get_config_name(args->program_name, &success, export_type));

			if (!success)
			{
				/* warn about unsuccessful match and the program's action of assuming 
				 * the configuration name is 'config' */
				fprintf(stderr, ANSI_RED"Warning: Your program is not supported (unknown default configuration).\n"STYLE_END);
			}
		}
		else
		{
			fprintf(stderr, "Unknown exporting type (undefined)\n");
			free(src_fp);
			free(dst_filename);
			exit(-1);
		}
	}

	char *dst_fp = bmalloc(path_template, home, path_to_config, args->program_name, dst_filename);

	free(dst_filename);

	/* currently only dst_fp & src_fp are allocated */

	/* switch config files & make the link */
	switch_config(src_fp, dst_fp);

	if (src_fp != NULL)
		free(src_fp);

	if (dst_fp != NULL)
		free(dst_fp);
}
