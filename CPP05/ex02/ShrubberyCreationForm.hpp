#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm(std::string);
		ShrubberyCreationForm(const ShrubberyCreationForm &);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &);
		virtual ~ShrubberyCreationForm();
};

#endif
