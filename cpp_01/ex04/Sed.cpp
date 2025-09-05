#include "Sed.hpp"

Sed::Sed(const std::string& filename, const std::string& s1, const std::string& s2)
	: filename(filename), s1(s1), s2(s2) {}

Sed::~Sed() {}

void Sed::process() 
{
	std::string content = readFile();
	std::string replaced = repalceAll(content);
	writeFile(replaced);
}

std::string Sed::readFile() 
{
	std::ifstream infile(filename.c_str());
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

std::string Sed::repalceAll(const std::string& content) 
{
	if (s1.empty())
		return content;

	std::string result;
	std::size_t pos = 0;
	std::size_t found;

	while ((found = content.find(s1, pos)) != std::string::npos) 
    {
		result += content.substr(pos, found - pos);
		result += s2;
		pos = found + s1.length();
	}
	result += content.substr(pos);
	return result;
}

void Sed::writeFile(const std::string& content) 
{
	std::ofstream outfile((filename + ".replace").c_str());
	if (!outfile.is_open()) 
    {
		std::cerr << "Error: cannot open output file" << std::endl;
		exit(1);
	}
	outfile << content;
	outfile.close();
}
