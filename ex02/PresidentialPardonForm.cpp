#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("defaultPresidentialPardonForm", 25, 5), _target("defaultTarget")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target) : Form("PresidentialPardonForm " + target, 25, 5), _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : Form(other.getName(), 25, 5), _target(other.getTarget())
{}

PresidentialPardonForm & PresidentialPardonForm::operator = (PresidentialPardonForm const &other)
{
	this->_target = other._target;
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const 
{
	if (this->getGradeExecute() < executor.getGrade())
		throw GradeTooLowException();
	else if (this->getIsSigned() == false)
		throw FormIsNotSigned();
	else
		std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
	return _target;
}

std::ostream &	operator << (std::ostream &ost, PresidentialPardonForm const &other)
{
	ost << other.getName() << " PresidentialPardonForm. GradeSign = " << other.getGradeSign() << ". GradeExecute = " << other.getGradeExecute() << ". Is signed = " << other.getIsSigned();
	return ost;
}
