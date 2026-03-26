#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string name)
	: AForm(name, 25, 5) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm(other) {
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this != &other) {
		_isSigned = other._isSigned;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {

}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (!getIsSigned()) {
		throw FormNotSignedException(getName());
	}
	if (executor.getGrade() > getGradeToExecute()) {
		throw GradeTooLowException(getName());
	}
	std::cout << _name << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
