#include <main.hpp>

#include <iostream>

int32_t main (int32_t argc, char* argv[])
{
	output_args(argc, argv);
	return 0;
}

void output_args (int32_t argc, char* argv[])
{
	uint32_t loopIdx = 0;
	uint32_t loopEnd = argc;

	std::cout << "Hello World!\n";
	std::cout << "Arguments Count: " << argc << "\n";
	std::cout << "Arguments:\n";

	while (loopIdx != loopEnd)
	{
		std::cout << "\t" << argv[loopIdx] << "\n";
		loopIdx++;
	}
}