#define _BSD_SOURCE
#define _DEFAULT_SOURCE

#include <sys/stat.h>
#include <unistd.h>

#include "header.h"

Bool is_link(const char *path);

int switch_config(const char *src, const char *dst)
{
	if (!(is_link(dst)))
	{
		/* check if there is a file at that location */
		FILE *fp = fopen(dst, "r");
		if (fp != NULL)
		{
			if (verbose)
			{
				printf("Found file conflicts at \'%s\'\n", dst);
			}

			/* archive the old config file to a new path */
			fclose(fp);
			char *cmd = bmalloc("mv %s archived-%s.old", dst, dst);
			system(cmd);
			free(cmd);
		}
	}
	else
	{
		if (verbose)
			printf("Link found at '%s' file path (overwritting the link ...)\n", dst);
	}

	const char *cmd_template = "ln -sf %s %s";
	char *cmd = bmalloc(cmd_template, src, dst);

	/* execute linking command
	 * links the configuration to the correct path */
	int ret = 0;

	if (verbose)
		printf(cmd);

	if (testing)
	{
		ret = system(cmd);
	}

	free(cmd);
	return ret;
}

Bool is_link(const char *path)
{
	struct stat file_stat;
	
	if (lstat(path, &file_stat) == -1)
	{
		err(LSTAT_FAIL);
	}
	
	if (S_ISLNK(file_stat.st_mode) == 0)
	{
		return False;
	}
	return True;
}
