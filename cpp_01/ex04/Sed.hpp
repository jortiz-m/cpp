#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

class Sed 
{
	public:
		Sed(const std::string& filename, const std::string& s1, const std::string& s2);
		~Sed();
		void process();

	private:
		std::string filename;
		std::string s1;
		std::string s2;

	std::string readFile();
	std::string repalceAll(const std::string& content);
	void 		writeFile(const std::string& content);
};

#endif
