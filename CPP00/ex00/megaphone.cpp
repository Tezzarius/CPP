#include <iostream>

int main(int ac, char **av) {
	if (ac == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int i = 1; i < ac; i++) {
		for (int j = 0; av[i][j]; j++) {
			if (j == 0 && av[i][j] == ' ')
				j++;
			if (av[i][j] == ' ' && !av[i][j+1])
				break;
			std::cout << (char)std::toupper(av[i][j]);
		}
		if (i < ac - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}