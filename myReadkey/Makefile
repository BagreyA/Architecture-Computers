FLAGS = -Wall -pedantic -ansi -lm -std=gnu11
OUT_FOLDER = ./bin
DEP_FILES = $(shell find ./ -maxdepth 1 -iname '*.c')
OBJ_FILES = $(patsubst %.c, $(OUT_FOLDER)/%.o, $(DEP_FILES))
LIB_NAME = libmyReadkey

prepare:
	mkdir -p $(OUT_FOLDER)

$(OUT_FOLDER)/%.o: %.c
	gcc $(FLAGS) -I../include/ -c $< -o $@

build: prepare $(OBJ_FILES)
	ar -rcs ${LIB_NAME}.a $(OUT_FOLDER)/*.o

clean:
	rm -rf $(OUT_FOLDER) ${LIB_NAME}.a