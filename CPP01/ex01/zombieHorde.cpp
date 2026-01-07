#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	Zombie* zombieHorde = new Zombie[N];
	for (int i = 0; i < N; i++) {
		std::stringstream num;
		num << i + 1;
		std::string fullname = name + num.str();
		zombieHorde[i].setName(fullname);
	}
	return zombieHorde;
}