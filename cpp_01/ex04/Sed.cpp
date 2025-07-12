#include "Sed.hpp"

Sed::Sed(const std::string& filename, const std::string& s1, const std::string& s2)
	: _filename(filename), _s1(s1), _s2(s2) {}

Sed::~Sed() {}

void Sed::process() 
{
	std::string content = _readFile();
	std::string replaced = _replaceAll(content);
	_writeFile(replaced);
}

std::string Sed::_readFile() 
{
	std::ifstream infile(_filename.c_str());
	if (!infile.is_open()) 
    {
		std::cerr << "Error: cannot open input file" << std::endl;
		exit(1);
	}

	std::string content;
	std::string line;
	while (std::getline(infile, line)) 
    {
		content += line;
		if (!infile.eof())
			content += "\n";
	}
	infile.close();
	return content;
}

std::string Sed::_replaceAll(const std::string& content) 
{
	if (_s1.empty())
		return content;

	std::string result;
	std::size_t pos = 0;
	std::size_t found;

	while ((found = content.find(_s1, pos)) != std::string::npos) 
    {
		result += content.substr(pos, found - pos);
		result += _s2;
		pos = found + _s1.length();
	}
	result += content.substr(pos);
	return result;
}

void Sed::_writeFile(const std::string& content) 
{
	std::ofstream outfile((_filename + ".replace").c_str());
	if (!outfile.is_open()) 
    {
		std::cerr << "Error: cannot open output file" << std::endl;
		exit(1);
	}
	outfile << content;
	outfile.close();
}
