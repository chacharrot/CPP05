#include "Bureaucrat.hpp"
#include "Form.hpp"

int main ()
{
	Bureaucrat pro("Pro", 1);
	Bureaucrat newbie("newbie", 150);
	Form	forNewbie("forNewbie", 150, 100);
	Form	forPro("forPro", 1, 1);
	
	newbie.signForm(forPro);
	newbie.signForm(forNewbie);
	pro.signForm(forNewbie);
	newbie.signForm(forNewbie);
	pro.signForm(forPro);
	return 0;
}