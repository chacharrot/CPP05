#ifndef FORM_H
# define FORM_H

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string 	_name;
		const unsigned int 	_gradeSign;
		const unsigned int 	_gradeExecute;
		bool				_isSigned;

	public:
		Form();
		Form(std::string const & name, unsigned int const gradeSign, unsigned int const gradeExecute);
		Form(Form const &other);
		~Form();
		Form & operator = (Form const &other);

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class FormIsSigned: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		std::string getName() const;
		unsigned int getGradeSign() const;
		unsigned int getGradeExecute() const;
		bool getIsSigned() const;
		void beSign(Bureaucrat const &some);
};

std::ostream &	operator << (std::ostream &ost, Form const &other);

#endif
