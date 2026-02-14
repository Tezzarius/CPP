#include "Zombie.hpp"

static int ft_stoi(std::string str) {
	int dest = 0;
	int neg = 1;
	int i;

	for (i = 0; str[i] == ' ' || str[i] == '\t'; i++);
	if (str[i] == '-' || str[i] == '+') {
		if (str[i] == '-')
			neg = -neg;
		i++;
	}
	for (int i = 0; str[i] >= '0' && str[i] <= '9'; i++) {
		dest *= 10;
		dest += str[i] - '0';
	}
	return dest * neg;
}

int main(int ac, char **av) {
	if (ac < 2 || ac > 3) {
		std::cout << "Invalid amount of arguments" << std::endl;
		return 1;
	}
	int N = ft_stoi(av[1]);
	if (N < 1) {
		std::cout << "You can't create a zombie horde with 0 zombies" << std::endl;
		return 1;
	}
	std::string name;
	if (ac == 3)
		name = av[2];
	else
		name = "Zombie";
	Zombie* Horde = zombieHorde(N, name);

	for (int i = 0; i < N; i++) {
		Horde[i].announce();
	}
	delete[] Horde;
	return 0;
}