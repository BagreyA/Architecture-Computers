FLAGS = -Wall -pedantic -ansi -lm -std=gnu11
OUT_FOLDER = ./bin
myTermLib = -L../myTerm/ -lmyTerm
mySimpleCompLib = -L../mySimpleComputer/ -lmySimpleComputer
myBigCharsLib = -L../myBigChars/ -lmyBigChars
myReadkeyLib = -L../myReadkey/ -lmyReadkey
HeadersDir = ../include
DEP_FILES = $(shell find ./ -maxdepth 1 -iname '*.c')
OBJ_FILES = $(patsubst %.c, $(OUT_FOLDER)/%.o, $(DEP_FILES))

$(OUT_FOLDER)/%.o: %.c
	gcc $(FLAGS) -I${HeadersDir} -I../mySimpleComputer -c $< -o $@

$(OUT_FOLDER):
	mkdir -p $(OUT_FOLDER)

build: $(OUT_FOLDER) $(OBJ_FILES)
	gcc -I${HeadersDir} -I../include ${OBJ_FILES} \
		${mySimpleCompLib} ${myTermLib} ${myBigCharsLib} ${myReadkeyLib}\
		-o ${OUT_FOLDER}/console

run: build
	${OUT_FOLDER}/console

build_font: ./fontGenerator/font.c
	gcc ./fontGenerator/font.c -o ./fontGenerator/font.out
	./fontGenerator/font.out

clean:
	rm -rf ./bin