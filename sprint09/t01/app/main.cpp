#include "src/Worker.h"
#include "src/MultithreadedClass.h"
#include <string>
#include <iostream>

static void usage(int argc) {
	if (argc != 4) {
		std::cerr << "usage: ./simpleWorkerV2 [addValue] [subtractValue] [count]\n";
		exit(1);
	}
}

void validation(char **argv) {
	auto pos = 0ul;
	try {
		int v1 = std::stoi(argv[1], &pos, 10);
		if (argv[1][pos] != '\0' || (v1 < -2000 || v1 > 2000))
			throw "";
	} catch(...) {
		std::cerr << "Incorrect values\n";
		exit(1);
	}
	try {
		int v2 = std::stoi(argv[2], &pos, 10);
		if (argv[2][pos] != '\0' || (v2 < -2000 || v2 > 2000))
			throw "";
	} catch(...) {
		std::cerr << "Incorrect values\n";
		exit(1);
	}
	try {
		int v3 = std::stoi(argv[3], &pos, 10);
		if (argv[3][pos] != '\0' || (v3 < 5 || v3 > 10))
			throw "";
	} catch(...) {
		std::cerr << "Incorrect values\n";
		exit(1);
	}
}


int main(int argc, char** argv) {
	usage(argc);
	validation(argv);
	MultithreadedClass obj;
	Worker worker;

	int count = std::stoi(argv[3]);
	int addValue = std::stoi(argv[1]);
	int subtractValue = std::stoi(argv[2]);

	for (auto i = 0; i < count; ++i) {
		worker.startNewThread(&MultithreadedClass::add, &obj, addValue);
	}
	for (auto i = 0; i < count; ++i) {
		worker.startNewThread(&MultithreadedClass::subtract, &obj, subtractValue);
	}
	worker.joinAllThreads();
	std::cout << obj.getInt() << std::endl;

	return 0;
}
