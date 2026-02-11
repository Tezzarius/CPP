#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string name)
	: AForm(name, 25, 5) {

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm(other) {

}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this != &other)
		isSigned = other.isSigned;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {

}

void PresidentialPardonForm::action() {
	
}