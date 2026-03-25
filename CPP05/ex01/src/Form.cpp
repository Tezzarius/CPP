#include "Debug.hpp"
#include "Form.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
	: _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	_isSigned = false;
	if (VERBOSE)
		std::cout << COLOUR << _name << " was created" << RESET << std::endl;
}

Form::Form(const Form &other)
	: _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
	if (VERBOSE)
		std::cout << COLOUR << _name << " was copied" << RESET << std::endl;
}

Form &Form::operator=(const Form &other) {
	if (this != &other)
		_isSigned = other._isSigned;
	if (VERBOSE)
		std::cout << COLOUR << _name << " was assigned" << RESET << std::endl;
	return *this;
}

Form::~Form() {
	if (VERBOSE)
		std::cout << COLOUR << _name << " was destroyed" << RESET << std::endl;
}

const std::string Form::getName() const{
	return _name;
}

bool Form::getIsSigned() const{
	return _isSigned;
}

int Form::getGradeToSign() const {
	return _gradeToSign;
}

int Form::getGradeToExecute() const{
	return _gradeToExecute;
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
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException(_name);
	else
		_isSigned = true;
}