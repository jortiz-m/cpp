#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv) 
{
    int i = 0;

	if (argc != 2) 
    {
		std::cerr << "Usage: ./harlFilter <level>" << std::endl;
		return 1;
	}

	std::string level = argv[1];
	Harl harl;
    
	int levelIndex = -1;
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    while (i < 4) 
    {
		if (level == levels[i]) 
        {
			levelIndex = i;
			break;
		}
        i++;
	}

	switch (levelIndex) 
    {
		case 0:
			harl.complain("DEBUG");
			// fall through
		case 1:
			harl.complain("INFO");
			// fall through
		case 2:
			harl.complain("WARNING");
			// fall through
		case 3:
			harl.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}

	return (0);
}
