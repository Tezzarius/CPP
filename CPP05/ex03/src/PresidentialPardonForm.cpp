#include "Debug.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string name)
	: AForm(name, 25, 5) {
	if (VERBOSE)
		std::cout << COLOUR << name << " was created" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm(other) {
	if (VERBOSE)
		std::cout << COLOUR << _name << " was copied" << RESET << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this != &other)
		_isSigned = other._isSigned;
	if (VERBOSE)
		std::cout << COLOUR << _name << " was assigned" << RESET << std::endl;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	if (VERBOSE)
		std::cout << COLOUR << _name << " was destroyed" << RESET << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (!getIsSigned())
		throw FormNotSignedException(getName());
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException(getName());
	std::cout << _name << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
