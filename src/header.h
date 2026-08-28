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
} command_args;

typedef enum
{
	INVALID_ERR = 0,
	ARG_MISSING = 1,
} err_type;

Bool cmp(char *arg, const char *s_one, const char *s_two);
Bool scmp(char *arg, char *s);
