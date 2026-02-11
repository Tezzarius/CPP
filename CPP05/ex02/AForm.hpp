#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class AForm {
	protected:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExecute;
	public:
		AForm(std::string, int, int);
		AForm(const AForm &);
		AForm &operator=(const AForm &);
		virtual ~AForm();

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

		virtual void beSigned(Bureaucrat &) = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &b);

#endif