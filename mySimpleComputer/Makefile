FLAGS = -Wall -pedantic -ansi -lm -std=gnu11
OUT_FOLDER = ./bin
DEP_FILES = $(shell find ./ -maxdepth 1 -iname '*.c')
OBJ_FILES = $(patsubst %.c, $(OUT_FOLDER)/%.o, $(DEP_FILES))
TEST_FOLDER = ./pr01
TEST_OUT_PATH = ../console/
LIB_NAME = libmySimpleComputer

prepare:
	mkdir -p $(OUT_FOLDER)

$(OUT_FOLDER)/%.o: %.c
	gcc $(FLAGS) -I../include -c $< -o $@

build: prepare $(OBJ_FILES)
	ar -rcs ${LIB_NAME}.a $(OUT_FOLDER)/*.o

test: build
	gcc ${TEST_FOLDER}/main.c $(FLAGS) -L. -lmySimpleComputer -o ${TEST_OUT_PATH}/pr01
	${TEST_OUT_PATH}/pr01

clean:
	rm -rf $(OUT_FOLDER) ${LIB_NAME}.a ${TEST_OUT_PATH}/pr01
