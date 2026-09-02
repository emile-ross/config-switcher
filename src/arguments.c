#include "header.h"

void arg_parser(arg_config_contents *args)
{
	if (args->program_name == NULL)
		err(INVALID_ARGS);

	const char *home = getenv("HOME");

	Bool style_is_used = False;	/* will be deprecated (newer enum config_switch_type) */
	char *src_fp = NULL;
	char *path_template = "%s/%s/%s/%s";

	if (args->src_filepath != NULL)
	{
		src_fp = bmalloc(path_template, home, path_to_config, args->program_name, args->src_filename);
	}
	else
		err(INVALID_ARGS);

	char *dst_filename = NULL;

	if (style_is_used)
		dst_filename = bmalloc("style.css");	/* defaults to style.css for the style name */
	else
	{
		Bool success = False;
		dst_filename = bmalloc(get_config_name(args->program_name, &success));

		if (!success)
		{
			/* warn about unsuccessful match and the program's action of assuming 
			 * the configuration name is 'config' */
			fprintf(stderr, ANSI_RED"Warning: Your program is not supported (unknown default configuration).\n"STYLE_END);
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
