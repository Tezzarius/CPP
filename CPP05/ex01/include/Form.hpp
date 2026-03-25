#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form {
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;
	public:
		Form(std::string, int, int);
		Form(const Form &);
		Form &operator=(const Form &);
		~Form();

		const std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		class GradeTooHighException : public std::exception {
			private:
				std::string msg;
			public:
				GradeTooHighException(const std::string &name);
				~GradeTooHighException() throw();

			const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			private:
				std::string msg;
			public:
				GradeTooLowException(const std::string &name);
				~GradeTooLowException() throw();
				
			const char *what() const throw();
		};

		void beSigned(Bureaucrat &b);
};

std::ostream &operator<<(std::ostream &os, const Form &b);

#endif