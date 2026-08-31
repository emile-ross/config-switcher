#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "enums.h"

/* compare.c */
	Bool cmp(char *arg, const char *s_one, const char *s_two);
	Bool scmp(char *arg, char *s);

/* errors.c */
	void err(err_type error_code);

/* match_config.c */
	char *get_config_name(char *program_name);

char *bmalloc(char *fmt, ...);

/* switch.c */
	int switch_config(const char *src, const char *dst);

extern const char *path_to_config;

