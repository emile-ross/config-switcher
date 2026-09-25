CC = gcc

SRC := compare errors main memory switch warn
PKG_NAME = config-switch
OUT = -o $(PKG_NAME)

SRC_FP := $(addprefix src/, $(SRC))
SRC_FILES := $(addsuffix .c, $(SRC_FP))

FLAGS := -Wall -Wextra -Wpedantic -std=c99 -Wconversion -Wshadow -Wundef -Wcast-qual -Wcast-align -Wswitch-enum

all: base
base: 
	@# adds the -Werror flag (treats warnings as errors)
	@$(CC) $(SRC_FILES) $(OUT) $(FLAGS) -Werror

base-e:
	# compiles the files with warnings
	$(CC) $(SRC_FILES) $(OUT) $(FLAGS)

