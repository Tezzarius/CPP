#include "Form.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
	: name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {

}

Form::Form(const Form &other)
	: name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {

}

Form &Form::operator=(const Form &other) {
	if (this != &other)
		isSigned = other.isSigned;
	return *this;
}

Form::~Form() {

}

const std::string Form::getName() const{
	return name;
}

bool Form::getIsSigned() const{
	return isSigned;
}

int Form::getGradeToSign() const {
	return gradeToSign;
}

int Form::getGradeToExecute() const{
	return gradeToExecute;
}

Form::GradeTooHighException::GradeTooHighException(const std::string &name) {
	msg = name + ": Grade toot high!";
}

const char *Form::GradeTooHighException::what() const throw() {
	return msg.c_str();
}

Form::GradeTooLowException::GradeTooLowException(const std::string &name) {
	msg = name + ": Grade too low!";
}

const char *Form::GradeTooLowException::what() const throw() {
	return msg.c_str();
}

Form::GradeTooHighException::~GradeTooHighException() throw() {

}

Form::GradeTooLowException::~GradeTooLowException() throw() {

}

std::ostream &operator<<(std::ostream &os, const Form &b) {
	os << b.getName() << ", is signed " << std::boolalpha << b.getIsSigned() << ", grade to sign " << b.getGradeToSign() << ", grade to execute " << b.getGradeToExecute() << ".";
	return os;
}

void Form::beSigned(Bureaucrat &b) {
	if (b.getGrade() > gradeToSign)
		throw GradeTooLowException(name);
	else
		isSigned = true;
}