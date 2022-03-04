#ifndef INTERN_H
#define INTERN_H

#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern() {}
	Intern(const Intern &other);
	~Intern() {}
	Intern & operator = (Intern const &other);
	

	Form *makeForm(std::string const & formName, std::string const & target);
};

#endif