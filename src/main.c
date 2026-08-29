#include "header.h"

const Bool verbose = True;

int main(int argc, char *argv[])
{
	uint8_t i = 1;	/* ignore first argument (arg 0) */
	command_args args = { NULL, NULL, NULL };

	if (!(argc > 2))
	{
		fprintf(stderr, "Missing arguments in command\n");
		return 1;
	}
	
	for (; i < (argc - 1); i++)
	{
		if (scmp(argv[i], "--help"))
		{
			printf("config-switcher [program] [file]\n");
			return 0;
		}
		else if (cmp(argv[i], "-s", "--style"))
		{
			if (i++ > argc)
				err(ARG_MISSING);
			args.style_name = argv[i];
			if (verbose)
				printf("%s\n", args.style_name);
		}
		else if (cmp(argv[i], "-c", "--config"))
		{
			if (i++ > argc)
				err(ARG_MISSING);
			args.config_name = argv[i];
			if (verbose)
				printf("%s\n", args.config_name);

		}
		else if (cmp(argv[i], "-p", "--program"))
		{
			if (i++ > argc)
				err(ARG_MISSING);
			args.program_name = argv[i];
			if (verbose)
				printf("%s\n", args.program_name);
		}
		else
		{
			fprintf(stderr, "Ignored arg: %s\n", argv[i]);
			fprintf(stderr, "You can view valid arguments using the --help flag\n");
			return 1;
		}
	}
	return 0;
}

void arg_parser(command_args *args)
{
	if (args->program_name == NULL)
		err(INVALID_ARGS);

	const char *home = getenv("HOME");

	Bool style = False;
	char *src_fp = NULL;
	char *path_template = "%s/%s/%s/%s";

	if (args->config_name != NULL)
		src_fp = bmalloc(path_template, home, path_to_config, args->program_name, args->config_name);
	else if (args->style_name != NULL)
	{
		style = True;
		src_fp = bmalloc(path_template, home, path_to_config, args->program_name, args->style_name);
	}
	else
		err(INVALID_ARGS);

	char *dst_filename = NULL;
	if (style)
		dst_filename = bmalloc("style.css");
	else
		dst_filename = bmalloc(get_config_name(args->program_name));

	char *dst_fp = bmalloc(path_template, home, path_to_config, args->program_name, dst_filename);

	switch_config(src_fp, dst_fp);
}
