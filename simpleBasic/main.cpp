#include <iostream>
#include <fstream>
#include <string>

#include "compiler.h"

using namespace std;

int main(int argc, char* argv[]) {
	if (argc < 3) {
		cout << "Неверные аргументы!\nПример: program.exe input.sb output.sa" << endl;
		return -1;
	}

	std::vector<std::string> all_args;

	if (argc > 1) {
		all_args.assign(argv + 1, argv + argc);
	}

	std::ifstream input_file(all_args[0]);
	std::ofstream output_file(all_args[1]);
	if (!input_file.is_open()) {
		cout << "Ошибка: не удается открыть входной файл" << endl;
		return -1;
	}
	if (!output_file.is_open()) {
		cout << "Ошибка: не удается открыть выходной файл" << endl;
		return -1;
	}

	Compiler compiler(input_file, output_file);
	compiler.compile();

	return 0;
}