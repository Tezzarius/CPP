#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string name)
	: AForm(name, 72, 45) {
	std::srand(std::time(0));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other) {
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other)
		isSigned = other.isSigned;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {

}

void RobotomyRequestForm::beSigned(Bureaucrat &) {

}

void RobotomyRequestForm::execute() {
	const int val = rand();
	if (val % 2 == 0)
		std::cout << name << " has been robotomized successfully." << std::endl;
	else
		std::cout << name << "s robotomy failed." << std::endl;
}