#include "Form.hpp"

Form::Form() : _name("defaultForm"), _gradeSign(150), _gradeExecute(150), _isSigned(false)
{}

Form::Form(std::string const & name, unsigned int const gradeSign, unsigned int const gradeExecute) : _name(name), _gradeSign(gradeSign), _gradeExecute(gradeExecute), _isSigned(false)
{
	if (gradeSign < 1 || gradeExecute < 1)
		throw GradeTooHighException();
	else if (gradeSign > 150 || gradeExecute > 150)
		throw GradeTooLowException();
}

Form::Form(Form const &other) : _name(other.getName()), _gradeSign(other.getGradeSign()), _gradeExecute(other.getGradeExecute()), _isSigned(other.getIsSigned())
{}

Form::~Form()
{}

Form & Form::operator = (Form const &other)
{
	this->_isSigned = other._isSigned;
	return *this;
}

std::string Form::getName() const
{
	return _name;
}

unsigned int Form::getGradeSign() const
{
	return _gradeSign;
}

unsigned int Form::getGradeExecute() const
{
	return _gradeExecute;
}

bool Form::getIsSigned() const
{
	return _isSigned;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "It's too high grade.";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "It's too low grade.";
}

const char *Form::FormIsSigned::what() const throw()
{
	return "Form is already signed.";
}

const char *Form::FormIsNotSigned::what() const throw()
{
	return "Form isn't signed.";
}

void Form::beSign(Bureaucrat const &some)
{
	if (_gradeSign < some.getGrade())
		throw GradeTooLowException();
	else if (_isSigned)
		throw FormIsSigned();
	else
		_isSigned = true;
}

std::ostream &	operator << (std::ostream &ost, Form const &other)
{
	ost << other.getName() << " Form. GradeSign = " << other.getGradeSign() << ". GradeExecute = " << other.getGradeExecute() << ". Is signed = " << other.getIsSigned();
	return ost;
}
