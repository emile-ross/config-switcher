#define _BSD_SOURCE
#define _DEFAULT_SOURCE

#include <sys/stat.h>
#include <unistd.h>

#include "header.h"

void switch_config(char *src, char *dst)
{
	struct stat file_stat;
	Bool is_link = False;
	if (lstat(dst, &file_stat) == -1)
	{
		fprintf(stderr, "lstat");
		exit(1);
	}

	if (S_ISLNK(file_stat.st_mode))
	{
		is_link = True;
	}
}
