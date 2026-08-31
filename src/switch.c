#define _BSD_SOURCE
#define _DEFAULT_SOURCE

#include <sys/stat.h>
#include <unistd.h>

#include "header.h"

Bool is_link(const char *path);

void switch_config(const char *src, const char *dst)
{
	if (!(is_link(dst)))
	{
		/* check if there is a file at that location */
		FILE *fp = fopen(dst, "r");
		if (fp != NULL)
		{
			/* archive the old config file to a new path */
			fclose(fp);
			char *cmd = bmalloc("mv %s archived-%s.old", dst, dst);
			system(cmd);
			free(cmd);
		}
	}

	/* TODO: create a symlink at the config file location */
	const char *cmd_template = "ln -sf %s %s";
	char *cmd = bmalloc(cmd_template, src, dst);

	/* use cmd buffer */

	free(cmd);
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
