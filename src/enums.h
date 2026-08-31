
typedef enum
{
	INVALID_ERR = 0,
	ARG_MISSING = 1,
	MISSING_INPUT_FILES = 2,
	ARG_NONE = 3,
	BUF_TRUNCATION = 21,
	LSTAT_FAIL = 22,
	INVALID_ARGS = 40,
	MALLOC_FAIL = 41
} err_type;

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
