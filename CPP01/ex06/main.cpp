#include "Harl.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Invalid amount of arguments" << std::endl;
		return 1;
	}
	std::string level[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	int levelIndex = -1;
	for (int i = 0; i < 4; i++) {
		if (level[i] == av[1]) {
			levelIndex = i; 
			break;
		}
	}
	Harl harl;

	switch(levelIndex) {
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			harl.complain("DEBUG");
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			harl.complain("INFO");
		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			harl.complain("WARNING");
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			harl.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}