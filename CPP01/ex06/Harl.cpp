#include "Harl.hpp"

Harl::Harl() {

}

Harl::~Harl() {

}

void Harl::_debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::_info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::_warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::_error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
	std::string levels[4];
	void (Harl::*functions[4])(void);

	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";
	
	functions[0] = &Harl::_debug;
	functions[1] = &Harl::_info;
	functions[2] = &Harl::_warning;
	functions[3] = &Harl::_error;

	int i;
	for (i = 0; levels[i].compare(level); i++);
	if (i < 4) {
		(this->*functions[i])();
	}
}