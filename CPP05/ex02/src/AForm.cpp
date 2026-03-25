#include "Debug.hpp"
#include "AForm.hpp"

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
	: _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
		_isSigned = false;
	if (VERBOSE)
		std::cout << COLOUR << _name << " was created" << RESET << std::endl;
}

AForm::AForm(const AForm &other)
	: _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
	if (VERBOSE)
		std::cout << COLOUR << _name << " was copied" << RESET << std::endl;
}

AForm &AForm::operator=(const AForm &other) {
	if (this != &other)
		_isSigned = other._isSigned;
	if (VERBOSE)
		std::cout << COLOUR << _name << " was assigned" << RESET << std::endl;
	return *this;
}

AForm::~AForm() {
	if (VERBOSE)
		std::cout << COLOUR << _name << " was destroyed" << RESET << std::endl;
}

const std::string AForm::getName() const{
	return _name;
}

bool AForm::getIsSigned() const{
	return _isSigned;
}

int AForm::getGradeToSign() const {
	return _gradeToSign;
}

int AForm::getGradeToExecute() const{
	return _gradeToExecute;
}

AForm::GradeTooHighException::GradeTooHighException(const std::string &name) {
	_msg = name + ": Grade too high!";
}

const char *AForm::GradeTooHighException::what() const throw() {
	return _msg.c_str();
}

AForm::GradeTooLowException::GradeTooLowException(const std::string &name) {
	_msg = name + ": Grade too low!";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return _msg.c_str();
}

AForm::FormNotSignedException::FormNotSignedException(const std::string &name) {
	_msg = name + ": Isn't signed!";
}

const char *AForm::FormNotSignedException::what() const throw() {
	return _msg.c_str();
}

AForm::GradeTooHighException::~GradeTooHighException() throw (){

}

AForm::GradeTooLowException::~GradeTooLowException() throw() {
	
}

AForm::FormNotSignedException::~FormNotSignedException() throw() {
	
}

std::ostream &operator<<(std::ostream &os, const AForm &b) {
	os << b.getName() << ", is signed " << std::boolalpha << b.getIsSigned() << ", grade to sign " << b.getGradeToSign() << ", grade to execute " << b.getGradeToExecute() << ".";
	return os;
}

void AForm::beSigned(Bureaucrat &b) {
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException(_name);
	else
		_isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const {
	(void)executor;
}