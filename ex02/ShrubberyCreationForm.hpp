#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm : public Form
{
	private:
		std::string 	_target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const & target);
		ShrubberyCreationForm(ShrubberyCreationForm const &other);
		~ShrubberyCreationForm() {}
		ShrubberyCreationForm & operator = (ShrubberyCreationForm const &other);

		std::string		_targetplus;
		void execute(Bureaucrat const & some) const;
		std::string getTarget() const;
};

std::ostream &	operator << (std::ostream &ost, ShrubberyCreationForm const &other);

#endif
