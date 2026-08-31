#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "enums.h"

/* compare.c */
	Bool cmp(const char *restrict arg, const char *restrict s_one, const char *restrict s_two);
	Bool scmp(const char *restrict arg, const char *restrict s);

/* errors.c */
	void err(err_type error_code);

/* match_config.c */
	char *get_config_name(const char *restrict program_name, Bool *success);

/* memory.c */
	char *bmalloc(const char *restrict fmt, ...);

/* switch.c */
	int switch_config(const char *src, const char *dst);

extern const char *path_to_config;

