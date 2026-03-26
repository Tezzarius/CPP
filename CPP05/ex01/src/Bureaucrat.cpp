#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
	if (grade < 1) {
		throw GradeTooHighException(_name);
	}
	if (grade > 150) {
		throw GradeTooLowException(_name);
	}
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {

}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other) {
		_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {

}

const std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::incrementGrade() {
	if (_grade <= 1) {
		throw GradeTooHighException(_name);
	}
	_grade--;
}

void Bureaucrat::decrementGrade() {
	if (_grade >= 150) {
		throw GradeTooLowException(_name);
	}
	_grade++;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &name) {
	_msg = name + ": Grade too high!";
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return _msg.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &name) {
	_msg = name + ": Grade too low!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return _msg.c_str();
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {

}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {
	
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}

void Bureaucrat::signForm(Form &f) {
	try {
		f.beSigned(*this);
		std::cout << _name << " signed " << f.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << _name << " couldn't sign " << f.getName() << " because " << e.what() << "." << std::endl;
	}
}
