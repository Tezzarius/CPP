#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Form;

class Bureaucrat {
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat(const std::string, int);
		Bureaucrat(const Bureaucrat &);
		Bureaucrat &operator=(const Bureaucrat &);
		~Bureaucrat();

		const std::string getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();

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

		void signForm(Form &f);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif