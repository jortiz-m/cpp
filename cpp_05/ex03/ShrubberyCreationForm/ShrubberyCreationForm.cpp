#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
: AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if(this != &other)
		_target = other._target;
	return *this;
}

const char* ShrubberyCreationForm::noSigned::what() const throw() 
{
	return ("Exception: it's no signed.");
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor)const
{
	if(!isSigned())
		throw (NoSigned());
	if((int)getGradeToExecute() < (int)executor.getGrade())
		throw (GradeTooLowException());

	std::ofstream file((_target + "_shrubbery").c_str());
	if(!file.is_open()){
		std::cerr << "Error: can't open file" << std::endl;
		return;
	}
	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣄⡀⠀⠀⠀⣶⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⣆⠀⠀⢻⡍⢳⡄⠀⠀⣿⠸⣆⠀⠀⣠⣤⣾⢳⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
	file << "⠀⠀⠀⠀⠀⠀⢀⣀⠀⢀⠀⢀⣀⠀⢸⢁⣿⡄⠀⠈⢷⣈⣿⠀⣠⣼⣦⣿⣴⣋⣡⠞⢻⠀⣿⢀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
	file << "⠀⠀⠀⠀⠀⠀⠘⢿⡻⣿⠳⣾⡍⠻⣿⣾⢿⡛⠶⣦⡄⠈⣿⣏⣡⠞⠋⣻⠉⠉⡀⠀⢸⡶⢟⣽⡯⠥⢤⣄⣀⡀⠀⠀⠀⠀⠀⠀\n";
	file << "⠀⠀⠀⠀⠀⠀⢀⣈⣛⣿⠀⢹⡿⠶⣼⣿⠀⠙⠶⢬⣷⣿⢸⡏⠀⠀⠀⡟⠀⢸⠹⣦⣾⠞⠋⠉⠛⠛⢿⠋⣻⠷⢲⣶⠆⠀⠀⠀\n";
	file << "⠀⠀⠀⢼⡿⣦⠸⣯⡉⠛⠷⣾⡃⠀⠀⢸⣇⠀⠀⠀⠈⣽⡇⢿⡄⠀⢀⡇⠀⢸⣠⡟⠀⠀⠀⠀⠀⠀⣸⣾⠥⠖⠋⠀⠀⠀⠀⠀\n";
	file << "⠀⠀⢰⣾⣧⢻⡆⠈⠉⠉⠙⠙⠻⣦⣀⠀⢿⣄⠀⠀⠀⣿⡇⠈⢻⣆⢸⡇⠀⣸⣿⢦⡀⠀⠀⣀⣤⣾⠋⠀⣀⣤⣶⣞⣉⡿⠆⠀\n";
	file << "⠀⠀⠘⣧⠈⢿⡃⠀⣀⣤⣤⣀⠀⠀⠙⠳⢶⣿⣦⡀⠀⣿⡇⠀⠀⢻⣿⣧⠞⢉⣿⣄⢻⡖⠛⠉⠉⠉⠉⠻⣿⣍⠛⣧⡀⠀⠀⠀\n";
	file << "⠀⢸⡿⢿⡷⠴⢷⡾⠥⠴⠞⠁⠀⠀⠀⠀⠀⠀⠉⠻⣦⣹⣇⠀⠀⠈⣿⡇⢀⡾⠉⣯⠛⠇⠀⠀⠀⠀⣀⣠⠞⠋⠓⠛⠟⠀⠀⠀\n";
	file << "⠀⠈⢷⡈⣷⡀⠈⠻⣆⠀⠀⢀⣠⡤⢤⣤⠀⠀⠀⠀⠘⢿⣿⡄⠀⠀⣼⣷⠋⢹⡀⣿⣀⣤⡤⠶⠒⠋⠹⣍⠳⣄⠀⠀⠀⠀⠀⠀\n";
	file << "⠀⠀⠀⠙⢿⣀⠀⠀⠙⠿⣦⡛⠛⠛⠛⠁⠀⠀⠀⠀⠀⠈⢿⣧⣴⠟⢻⡇⢀⣤⠿⣿⣉⡀⠀⠀⣀⡀⠀⠈⠛⠛⠃⠀⢀⣠⣤⠀\n";
	file << "⠀⠀⠀⠀⠀⠉⠙⠛⠲⠶⠿⠿⣦⣄⣀⣀⣀⣀⣀⠀⠀⠀⢸⣿⠏⠀⢸⣷⠋⠁⠀⠀⠉⠉⠛⠛⣿⠙⢲⡄⠀⣀⣴⣾⡽⠾⠛⠀\n";
	file << "⢰⢦⣄⠀⠀⢴⣚⣛⣶⣶⠀⠀⠀⠉⠛⠛⠻⠿⠿⠿⣷⣦⣼⣿⡄⠀⣿⡇⠀⠀⠀⠀⠀⣀⣀⣤⣬⡿⠶⠛⢩⣿⢯⣉⠛⢶⡄⠀\n";
	file << "⠘⢦⣌⣷⡄⠀⠀⠀⠀⠙⢶⣤⣀⡀⠀⠀⣀⣀⣀⣀⠈⠛⣿⣿⠇⣰⣿⣧⣶⣾⣿⠿⠿⠛⠉⠘⣧⢻⡄⠀⣾⢹⡆⠈⠙⠛⠛⠀\n";
	file << "⠀⠀⢈⡛⠷⠦⣤⣤⣤⡤⠴⠿⠿⠛⠛⠛⠋⠛⠛⠻⢿⣦⣼⣿⣠⣿⠋⠁⠀⠉⠙⠛⢳⣶⡞⠛⠻⣾⡏⠙⢿⡿⣧⣴⣶⠶⢤⣀\n";
	file << "⠀⠀⡟⢹⡄⠀⠀⠀⠀⡞⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣿⣿⣿⡏⠀⠀⠀⠀⠀⠀⢸⣁⣿⠀⠀⠀⠀⠀⠀⠀⠙⢷⡈⠻⣞⠉\n";
	file << "⠀⠀⢷⡾⠀⠀⠀⠀⠀⠻⣼⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⠃⠀⠀⠀⠀⠀⠀⠘⠿⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠛⠿⠀\n";
	file << "⠀⠀⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << "               ,@@@@@@@,\n";
	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n";
	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n";
	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ " << "   `&%\\ ` /%&'    |.|        \\ '|8'\n";
	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⣿⣿⣿⣷⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << "       |o|        | |         | |\n";
	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣤⣿⠟⠛⢻⣯⠙⠻⠿⠿⠷⣦⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << "       |.|        | |         | |\n";
	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠁⠀⠀⠘⠛⠀⠀⠀⠀⠀⠀⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << "\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n";
	file.close();
}
