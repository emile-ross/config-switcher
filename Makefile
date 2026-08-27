CC = gcc

SRC := main
PKG_NAME = config-switch
OUT = -o $(PKG_NAME)

SRC_FP := $(addprefix src/, $(SRC))
SRC_FILES := $(addsuffix .c, $(SRC_FP))

FLAGS := -Wall -Wextra -Wpedantic -std=c89 -Wconversion -Wshadow -Wundef -Wcast-qual -Wcast-align

all: base

base: 
	$(CC) $(SRC_FILES) $(OUT) $(FLAGS)
