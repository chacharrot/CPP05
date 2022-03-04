#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main ()
{
	Intern intern;
	Bureaucrat pro("Pro", 1);
	Bureaucrat newbie("Newbie", 71);
	Form *formS = intern.makeForm("shrubbery creation", "home");
	Form *formR = intern.makeForm("robotomy request", "scha");
	Form *formP = intern.makeForm("presidential pardon", "prisoner");

	std::cout << *formS << std::endl;
	std::cout << *formR << std::endl;
	std::cout << *formP << std::endl;
	std::cout << std::endl;

	newbie.signForm(*formS);
	pro.signForm(*formS);
	std::cout << std::endl;

	newbie.executeForm(*formS);
	pro.executeForm(*formS);
	std::cout << std::endl;

	newbie.signForm(*formR);
	pro.signForm(*formR);
	std::cout << std::endl;

	newbie.executeForm(*formR);
	pro.executeForm(*formR);
	std::cout << std::endl;

	newbie.signForm(*formP);
	pro.signForm(*formP);
	std::cout << std::endl;

	newbie.executeForm(*formP);
	pro.executeForm(*formP);
	delete formS;
	delete formR;
	delete formP;

}