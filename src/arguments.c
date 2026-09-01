#include "header.h"

void arg_parser(command_args *args)
{
	if (args->program_name == NULL)
		err(INVALID_ARGS);

	const char *home = getenv("HOME");

	Bool style = False;
	char *src_fp = NULL;
	char *path_template = "%s/%s/%s/%s";

	if (args->config_name != NULL)
	{
		src_fp = bmalloc(path_template, home, path_to_config, args->program_name, args->config_name);
	}
	else if (args->style_name != NULL)
	{
		style = True;
		src_fp = bmalloc(path_template, home, path_to_config, args->program_name, args->style_name);
	}
	else
		err(INVALID_ARGS);

	char *dst_filename = NULL;

	if (style)
		dst_filename = bmalloc("style.css");	/* defaults to style.css for the style name */
	else
	{
		Bool success = False;
		dst_filename = bmalloc(get_config_name(args->program_name, &success));

		if (!success)
		{
			/* warn about unsuccessful match and the program's action of assuming 
			 * the configuration name is 'config' */
			fprintf(stderr, "Your program is not supported (unknown default configuration).\n");
			exit(1);;
		}
	}

	char *dst_fp = bmalloc(path_template, home, path_to_config, args->program_name, dst_filename);
	free(dst_filename);

	/* currently only dst_fp & src_fp are allocated */

	/* switch config files & make the link */
	switch_config(src_fp, dst_fp);

	free(src_fp);
	free(dst_fp);
}
