#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form {
	private:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExecute;
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
			const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			const char *what() const throw();
		};

		void beSigned(Bureaucrat &b);
};

std::ostream &operator<<(std::ostream &os, const Form &b);

#endif