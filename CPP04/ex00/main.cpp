#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
	const Animal* alpha = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << "Dog type: " << dog->getType() << std::endl;
	std::cout << "Cat type: " << cat->getType() << std::endl;
	std::cout << "The Cat make: ";
	cat->makeSound();
	std::cout << "The Dog make: ";
	dog->makeSound();
	std::cout << "The Animal make: ";
	alpha->makeSound();
	delete alpha;
	delete dog;
	delete cat;

	std::cout << std::endl;

	const WrongAnimal* beta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << "WrongCat type: " << wrongCat->getType() << std::endl;
	std::cout << "The WrongCat make: ";
	wrongCat->makeSound();
	std::cout << "The WrongAnimal make: ";
	beta->makeSound();
	
	delete beta;
	delete wrongCat;

	return 0;
}