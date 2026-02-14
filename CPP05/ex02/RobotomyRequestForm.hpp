#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm(std::string);
		RobotomyRequestForm(const RobotomyRequestForm &);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &);
		virtual ~RobotomyRequestForm();

		virtual void beSigned(Bureaucrat &);

		void execute();
};

#endif