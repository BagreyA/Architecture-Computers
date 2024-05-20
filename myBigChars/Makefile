CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=gnu11
SRCDIR = .
OBJ_DIR = ./obj
LIBDIR = .

SRCS := $(wildcard $(SRCDIR)/*.c)
#SRCS := $(filter-out $(SRCDIR)/main.c, $(wildcard $(SRCDIR)/*.c))
OBJS := $(patsubst $(SRCDIR)/%,$(OBJ_DIR)/%,$(SRCS:.c=.o))

LIB_FILE = $(LIBDIR)/libmyBigChars.a

.PHONY: all clean

all: build

build: $(LIB_FILE)

$(LIB_FILE): $(OBJS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRCDIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I. -I../include -I../myTerm -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR) $(LIB_FILE) *.bin *.o