#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <fstream>
#include <string>

class Sed 
{
public:
	Sed(const std::string& filename, const std::string& s1, const std::string& s2);
	~Sed();

	void process();

private:
	std::string _filename;
	std::string _s1;
	std::string _s2;

	std::string _readFile();
	std::string _replaceAll(const std::string& content);
	void _writeFile(const std::string& content);
};

#endif
