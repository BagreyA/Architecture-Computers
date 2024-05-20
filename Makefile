.PHONY: all run build_console build_sc build_mt format clean run_console

all: build_sc build_mt build_bc build_rk build_console

run: all
	$(MAKE) -C ./console/ run
build_console:
	$(MAKE) -C ./console/ build
build_sc:
	$(MAKE) -C ./mySimpleComputer/ build
build_mt:
	$(MAKE) -C ./myTerm/ build
build_bc:
	$(MAKE) -C ./myBigChars/ build

build_rk:
	$(MAKE) -C ./myReadkey/ build

clean: 
	$(MAKE) -C ./console/ clean
	$(MAKE) -C ./mySimpleComputer/ clean
	$(MAKE) -C ./myTerm/ clean
	$(MAKE) -C ./myBigChars/ clean
	$(MAKE) -C ./myReadkey/ clean

format: 
	find . -type f -name '*.[ch]' | xargs clang-format --style GNU -i --verbose