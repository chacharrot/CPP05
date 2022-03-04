#include "Bureaucrat.hpp"
#include "Form.hpp"

int main ()
{
	Bureaucrat pro("Pro", 1);
	Bureaucrat newbie("newbie", 150);
	Form	forNewbie("forNewbie", 150, 100);
	Form	forPro("forPro", 1, 1);
	
	newbie.signForm(forPro);
	try
	{
		forPro.beSign(newbie);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	newbie.signForm(forNewbie);
	try
	{
		forPro.beSign(pro);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	newbie.signForm(forNewbie);
	try
	{
		forPro.beSign(pro);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	return 0;
}