#include "Debug.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name) {
	if (grade < 1)
		throw GradeTooHighException(name);
	if (grade > 150)
		throw GradeTooLowException(name);
	this->grade = grade;
	if (VERBOSE)
		std::cout << COLOUR << name << " was created" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {
	if (VERBOSE)
		std::cout << COLOUR << name << " was copied" << RESET << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other) {
		grade = other.grade;
	}
	if (VERBOSE)
		std::cout << COLOUR << name << " was assigned" << RESET << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat() {
	if (VERBOSE)
		std::cout << COLOUR << name << " was destroyed" << RESET << std::endl;
}

const std::string Bureaucrat::getName() const {
	return name;
}

int Bureaucrat::getGrade() const {
	return grade;
}

void Bureaucrat::incrementGrade() {
	if (grade <= 1)
		throw GradeTooHighException(name);
	grade--;
}

void Bureaucrat::decrementGrade() {
	if (grade >= 150)
		throw GradeTooLowException(name);
	grade++;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &name) {
	msg = name + ": Grade too high!";
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return msg.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &name) {
	msg = name + ": Grade too low!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return msg.c_str();
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {

}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {
	
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}

void Bureaucrat::signForm(AForm &f) {
	try {
		f.beSigned(*this);
	} catch (std::exception &e) {
		std::cout << name << " couldn't sign " << f.getName() << " because " << e.what() << "." << std::endl;
	}
	if (f.getIsSigned() == true)
		std::cout << name << " signed " << f.getName() << std::endl;
}

void Bureaucrat::executeForm(AForm const &form) const {
	if (form.getIsSigned() == false)
		std::cout << name << " couln't execute " << form.getName() << ", " << form.getName() << " isn't signed." << std::endl;
	else if (getGrade() > form.getGradeToExecute())
		std::cout << name << " couln't execute " << form.getName() << ", " << name << "s grade is to low!" << std::endl;
	else {
		form.execute(*this);
		std::cout << name << " executed " << form.getName() << "." << std::endl;
	}
}