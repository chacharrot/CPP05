#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main ()
{
	Bureaucrat pro("Pro", 1);
	Bureaucrat newbie("Newbie", 71);
	Form *formS = new ShrubberyCreationForm("tree");
	Form *formR = new RobotomyRequestForm("arm");
	Form *formP = new PresidentialPardonForm("free");

	std::cout << *formS << std::endl;
	std::cout << *formR << std::endl;
	std::cout << *formP << std::endl;
	std::cout << std::endl;

	newbie.signForm(*formS);
	pro.signForm(*formS);
	newbie.executeForm(*formS);
	pro.executeForm(*formS);
	std::cout << std::endl;

	newbie.signForm(*formR);
	pro.signForm(*formR);
	newbie.executeForm(*formR);
	pro.executeForm(*formR);
	std::cout << std::endl;
	
	newbie.signForm(*formP);
	pro.signForm(*formP);
	newbie.executeForm(*formP);
	pro.executeForm(*formP);
	delete formS;
	delete formR;
	delete formP;

}