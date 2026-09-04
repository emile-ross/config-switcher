#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "enums.h"
#include "structs.h"

#define ANSI_RED	"\x1b[31m"
#define ANSI_WHITE	"\x1b[97m"
#define ANSI_YELLOW	"\x1b[33m"

#define BOLD_S		"\x1B[1m" 
#define UDRL_S  	"\x1B[4m" 

#define STYLE_END	"\x1B[0m" 

/* compare.c */
	Bool cmp(const char *restrict arg, const char *restrict s_one, const char *restrict s_two);
	Bool scmp(const char *restrict arg, const char *restrict s);

/* errors.c */
	void err(err_type error_code);
	void ignored_arg(char *flag);

/* match_config.c */
	char *get_config_name(const char *restrict program_name, Bool *success, enum config_switch_type export_type);

/* memory.c */
	char *bmalloc(const char *restrict fmt, ...);

/* switch.c */
	int switch_config(const char *src, const char *dst);

/* arguments.c */
	void arg_parser(arg_config_contents *args, enum config_switch_type export_type);

/* path.c */
	extern const char *path_to_config;

/* main.c gloal variables */
	extern const Bool verbose;
	extern const Bool testing;
