#include "Bureaucrat.hpp"

int main ()
{
	Bureaucrat worker("Worker", 6);

	try
	{
		worker.incrementGrade();
		std::cout << worker << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << worker << std::endl;
		std::cerr << e.what() << std::endl;
	}

	try
	{
		worker.decrementGrade();
		std::cout << worker << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << worker << std::endl;
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat pro("Pro", 0);
		std::cout << pro << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat newbie("Newbie", 155);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}