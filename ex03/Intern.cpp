#include "Intern.hpp"

Intern::Intern(const Intern &other)
{
	static_cast<void>(other);
}

Intern & Intern::operator = (Intern const &other)
{
	static_cast<void>(other);
	return *this;
}

Form *shrForm(std::string const & formName, std::string const & target)
{
	std::cout << "Intern creates " << formName << std::endl;
	return new ShrubberyCreationForm(target);
}

Form *robotForm(std::string const & formName, std::string const & target)
{
	std::cout << "Intern creates " << formName << std::endl;
	return new RobotomyRequestForm(target);
}

Form *presidentForm(std::string const & formName, std::string const & target)
{
	std::cout << "Intern creates " << formName << std::endl;
	return new PresidentialPardonForm(target);
}

Form *noForm(std::string const & formName, std::string const & target)
{
	std::cout << "There is no form of name " << formName << std::endl;
	(void)target;
	return NULL;
}

Form *Intern::makeForm(std::string const & formName, std::string const & target)
{
	std::string find[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	Form* (*formFunctions[4])(std::string const & formName, std::string const & target) = {&shrForm, &robotForm, &presidentForm, &noForm};
	int i = 0;

	while (i < 3 && find[i] != formName)
		i++;
	return (formFunctions[i](formName, target));
}
