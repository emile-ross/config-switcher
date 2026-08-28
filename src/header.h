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

Bool cmp(char *arg, const char *s_one, const char *s_two);
Bool scmp(char *arg, char *s);
