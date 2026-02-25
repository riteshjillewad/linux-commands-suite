############################################################
# Linux Command Suite - Makefile
# Author : Ritesh Jillewad
############################################################

CC      = gcc
CFLAGS  = -Wall -Wextra -std=c11 -O2

SRC_DIR = src
BIN_DIR = bin

# Automatically detect all .c files inside src
SOURCES = $(wildcard $(SRC_DIR)/*.c)

# Convert src/myls.c -> bin/myls
TARGETS = $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%, $(SOURCES))

############################################################

# Default target
all: $(BIN_DIR) $(TARGETS)
	@echo "All commands compiled successfully."

# Create bin directory if not exists
$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

# Rule to compile each command
$(BIN_DIR)/%: $(SRC_DIR)/%.c
	@echo "Building $< ..."
	@$(CC) $(CFLAGS) $< -o $@

# Clean all binaries
clean:
	@echo "Cleaning..."
	@rm -rf $(BIN_DIR)
	@echo "Done."

.PHONY: all clean
