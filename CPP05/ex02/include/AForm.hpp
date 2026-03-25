#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class AForm {
	protected:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;
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
			private:
				std::string _msg;
			public:
				GradeTooHighException(const std::string &name);
				virtual ~GradeTooHighException() throw();

			virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			private:
				std::string _msg;
			public:
				GradeTooLowException(const std::string &name);
				virtual ~GradeTooLowException() throw();

			virtual const char *what() const throw();
		};
		class FormNotSignedException : public std::exception {
			private:
				std::string _msg;
			public:
				FormNotSignedException(const std::string &name);
				virtual ~FormNotSignedException() throw();
				
			virtual const char *what() const throw();
		};

		void beSigned(Bureaucrat &);
		virtual void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &os, const AForm &b);

#endif