# Compiler and flags
CC = gcc
CFLAGS = -Wall -I$(INCLUDE_DIR)
LDFLAGS = -L$(LIB_DIR)
LIBS = # Add any actual libraries here if necessary (e.g., -lm)

# Directories
SRC_DIR = .
OBJ_DIR = ./build
INCLUDE_DIR = ./header
LIB_DIR = ./lib

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(LIB_DIR)/*.c)
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(SRCS)))

# Output binary
TARGET = $(OBJ_DIR)/main  # Change to actual binary name

# Default target
all: $(TARGET)

# Rule to build the target
$(TARGET): $(OBJS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBS)

# Rule to compile source files into object files from SRC_DIR
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to compile source files into object files from LIB_DIR
$(OBJ_DIR)/%.o: $(LIB_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -rf $(OBJ_DIR)/*
	@mkdir -p $(OBJ_DIR)

# PHONY targets to avoid conflicts
.PHONY: all clean
