#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "enums.h"

#define ANSI_RED	"\x1b[31m"
#define ANSI_WHITE	"\x1b[97m"
#define ANSI_YELLOW	"\x1b[33m"

#define BOLD		"\x1B[1m" 
#define UDRL		"\x1B[4m" 

#define RESET		"\x1B[0m" 

/* 8 bit */
	#define INT8MAX (127)
	#define INT8MIN (-127)
	
	#define UINT8MAX (255)

/* 16 bit */
	#define INT16MIN (32767)
	#define INT16MAX (32767)
	
	#define UINT16MAX (65535)

/* 32 bit */
	#define INT32MAX (2147483647)
	#define INT32MIN (-2147483647)
	
	#define UINT32MAX (4294967295)

/* compare.c */
	Bool cmp(const char *restrict arg, const char *restrict s_one, const char *restrict s_two);
	Bool scmp(const char *restrict arg, const char *restrict s);

/* errors.c */
	void err(err_type error_code);
	void ignored_arg(const char *flag);

/* warn.c */
	void warn(const char *restrict fmt, ...);

/* main.c gloal variables */
	extern const Bool verbose;
	extern const Bool testing;

/* memory.c */
	char *bmalloc(size_t *buffer_size, const char *restrict fmt, ...);

/* path.c */
	extern const char *path_to_config;

/* switch.c */
	int switch_config(const char *src, const char *dst);


void lookup_keyword(char *switching_keyword);
