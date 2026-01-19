#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();

	std::cout << "Dog type: " << dog->getType() << std::endl;
	std::cout << "Cat type: " << cat->getType() << std::endl;

	std::cout << "The Cat make: ";
	cat->makeSound();
	std::cout << "The Dog make: ";
	dog->makeSound();

	delete dog;
	delete cat;

	std::cout << std::endl;

	Animal *animals[10];

	for (int i = 0; i < 5; i++)
		animals[i] = new Dog();
	for (int i = 5; i < 10; i++)
		animals[i] = new Cat();

	for (int i = 0; i < 10; i++)
		delete animals[i];

	std::cout << std::endl;

	Dog a;
	Dog b(a);

	std::cout << std::endl;

	Dog c;
	Dog d;

	d = a;

	std::cout << std::endl;

	return 0;
}