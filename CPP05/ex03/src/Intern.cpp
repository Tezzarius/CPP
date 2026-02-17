#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

AForm *Intern::makeForm(std::string form, std::string name) {
	std::string forms[3];
	AForm *functions[3];

	forms[0] = "presidential pardon";
	forms[1] = "robotomy request";
	forms[2] = "shrubbery creation";

	functions[0] = new PresidentialPardonForm(name);
	functions[1] = new RobotomyRequestForm(name);
	functions[2] = new ShrubberyCreationForm(name);

	int i;
	for (i = 0; i < 3 && forms[i].compare(form); i++);
	if (i < 3) {
		for (int j = 0; j < 3; j++) {
			if (j != i)
				delete functions[j];
		}
		std::cout << "Intern creates " << form << std::endl;
		return functions[i];
	}
	for (int j = 0; j < 3; j++)
		delete functions[j];
	std::cout << "Intern couldn't create " << form << ", this form doesn't exist." << std::endl;
	return NULL;
}