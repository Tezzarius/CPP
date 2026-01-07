#include "Zombie.hpp"

int main() {
	Zombie* Brainy = newZombie("Brainy");
	randomChump("Bitey McBiteFace");
	Brainy->announce();
	delete Brainy;
	return 0;
}