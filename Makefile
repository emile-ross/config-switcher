CC = gcc

SRC_FILES := main.c

FLAGS := -Wall -Wextra -Wpedantic -std=c89 -Wconversion -Wshadow -Wundef -Wcast-qual -Wcast-align

all: base

base: 
	$(CC) $(SRC_FILES) $(FLAGS)
