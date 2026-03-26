#include "Bureaucrat.hpp"
#include "AForm.hpp"

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
	_msg = name + ": _Grade too high!";
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return _msg.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &name) {
	_msg = name + ": _Grade too low!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return _msg.c_str();
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {

}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {
	
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b) {
	os << b.getName() << ", bureaucrat _grade " << b.getGrade() << ".";
	return os;
}

void Bureaucrat::signForm(AForm &f) {
	try {
		f.beSigned(*this);
	} catch (std::exception &e) {
		std::cout << _name << " couldn't sign " << f.getName() << " because " << e.what() << "." << std::endl;
	}
	if (f.getIsSigned() == true) {
		std::cout << _name << " signed " << f.getName() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form) const {
	if (form.getIsSigned() == false) {
		std::cout << _name << " couln't execute " << form.getName() << ", " << form.getName() << " isn't signed." << std::endl;
	}
	else if (getGrade() > form.getGradeToExecute()) {
		std::cout << _name << " couln't execute " << form.getName() << ", " << _name << "s _grade is to low!" << std::endl;
	}
	else {
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << "." << std::endl;
	}
}