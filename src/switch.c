#define _BSD_SOURCE
#define _DEFAULT_SOURCE

#include <sys/stat.h>
#include <unistd.h>

#include "header.h"

void switch_config(const char *src, const char *dst)
{
	if (check_link(dst))
	{
		FILE *fp = fopen(dst, "r");
		if (fp != NULL)
		{
			fclose(fp);
			/* */
		}
	}
}

Bool check_link(char *path)
{
	struct stat file_stat;
	
	if (lstat(path, &file_stat) == -1)
	{
		fprintf(stderr, "lstat() failed\n");
		exit(1);
	}
	
	if (S_ISLNK(file_stat.st_mode))
	{
		return False;
	}
	return True;
}
