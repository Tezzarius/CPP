#include "Debug.hpp"
#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string name)
	: AForm(name, 72, 45) {
	std::srand(std::time(0));
	if (VERBOSE)
		std::cout << COLOUR << name << " was created" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other) {
	if (VERBOSE)
		std::cout << COLOUR << _name << " was copied" << RESET << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other)
		_isSigned = other._isSigned;
	if (VERBOSE)
		std::cout << COLOUR << _name << " was assigned" << RESET << std::endl;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	if (VERBOSE)
		std::cout << COLOUR << _name << " was destroyed" << RESET << std::endl;
}

void RobotomyRequestForm::beSigned(Bureaucrat &) {

}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (!getIsSigned())
		throw FormNotSignedException(getName());
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException(getName());	
	const int val = rand();
	if (val % 2 == 0)
		std::cout << _name << " has been robotomized successfully." << std::endl;
	else
		std::cout << _name << "s robotomy failed." << std::endl;
}