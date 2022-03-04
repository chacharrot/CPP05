#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("defaultRobotomyRequestForm", 72, 45), _target("defaultTarget")
{}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) : Form("RobotomyRequestForm " + target, 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : Form(other.getName(), 72, 45), _target(other.getTarget())
{}

RobotomyRequestForm & RobotomyRequestForm::operator = (RobotomyRequestForm const &other)
{
	this->_target = other._target;
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getGradeExecute() < executor.getGrade())
		throw GradeTooLowException();
	else if (this->getIsSigned() == false)
		throw FormIsNotSigned();
	else
		std::cout << "dudududu, ziiiiiing. " << _target << " has been robotomized successfully 50\% of the time" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
	return _target;
}

std::ostream &	operator << (std::ostream &ost, RobotomyRequestForm const &other)
{
	ost << other.getName() << " RobotomyRequestForm. GradeSign = " << other.getGradeSign() << ". GradeExecute = " << other.getGradeExecute() << ". Is signed = " << other.getIsSigned();
	return ost;
}
