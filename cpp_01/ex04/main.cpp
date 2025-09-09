#include "Sed.hpp"

int main(int argc, char **argv) 
{
	if (argc != 4) 
    {
		std::cerr << "Usage: ./Sed <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	Sed sed(filename, s1, s2);
	sed.process();

	return (0);
}
