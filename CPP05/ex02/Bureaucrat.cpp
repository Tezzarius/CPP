#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name) {
	if (grade < 1)
		throw GradeTooHighException(name);
	if (grade > 150)
		throw GradeTooLowException(name);
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {

}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other) {
		grade = other.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {

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
