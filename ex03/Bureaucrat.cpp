#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string const & name, unsigned int const grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other.getName()), _grade(other.getGrade())
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat & Bureaucrat::operator = (Bureaucrat const &other)
{
	this->_grade = other._grade;
	return *this;
}

std::string Bureaucrat::getName() const
{
	return _name;
}

unsigned int Bureaucrat::getGrade() const
{
	return _grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "It's too high grade.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "It's too low grade.";
}

void Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw GradeTooHighException();
	else
		_grade--;

}

void Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw GradeTooLowException();
	else
		_grade++;
}

void Bureaucrat::signForm(Form &form)
{
	if (form.getIsSigned() == false && form.getGradeSign() >= _grade)
		std::cout << _name << " signs " << form.getName() << std::endl;
	try
	{
		form.beSign(*this);
	}
	catch (const std::exception& e) 
	{
		std::cout << _name << " cannot sign form " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const Form & form)
{
	try
	{
		form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cout << this->_name << " cannot execute " << form.getName() << " because "<< e.what() << std::endl;
		return;
	}
	std::cout << this->getName() << " executes " << form.getName() << std::endl;
}


std::ostream &	operator << (std::ostream &ost, Bureaucrat const &worker)
{
	ost << worker.getName() << ", bureaucrat grade " << worker.getGrade();
	return ost;
}
