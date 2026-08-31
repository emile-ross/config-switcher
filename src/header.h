#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef enum
{
	False = 0,
	True = 1
} Bool;

typedef struct
{
	char *program_name;
	char *config_name;
	char *style_name;
} command_args;

typedef enum
{
	INVALID_ERR = 0,
	ARG_MISSING = 1,
	MISSING_INPUT_FILES = 2,
	BUF_TRUNCATION = 21,
	LSTAT_FAIL = 22,
	INVALID_ARGS = 40,
	MALLOC_FAIL = 41
} err_type;

/* compare.c */
	Bool cmp(char *arg, const char *s_one, const char *s_two);
	Bool scmp(char *arg, char *s);

/* errors.c */
	void err(err_type error_code);

/* match_config.c */
	char *get_config_name(char *program_name);

char *bmalloc(char *fmt, ...);

extern const char *path_to_config;


/* switch.c */
	void switch_config(const char *src, const char *dst);

