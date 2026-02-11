#include "AForm.hpp"

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
	: name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {

}

AForm::AForm(const AForm &other)
	: name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {

}

AForm &AForm::operator=(const AForm &other) {
	if (this != &other)
		isSigned = other.isSigned;
	return *this;
}

AForm::~AForm() {

}

const std::string AForm::getName() const{
	return name;
}

bool AForm::getIsSigned() const{
	return isSigned;
}

int AForm::getGradeToSign() const {
	return gradeToSign;
}

int AForm::getGradeToExecute() const{
	return gradeToExecute;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "Form: Grade too high!";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Form: Grade too low!";
}

std::ostream &operator<<(std::ostream &os, const AForm &b) {
	os << b.getName() << ", is signed " << std::boolalpha << b.getIsSigned() << ", grade to sign " << b.getGradeToSign() << ", grade to execute " << b.getGradeToExecute() << ".";
	return os;
}

void AForm::beSigned(Bureaucrat &b) {
	if (b.getGrade() > gradeToSign)
		throw GradeTooLowException();
	else
		isSigned = true;
}