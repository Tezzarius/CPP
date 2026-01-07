#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <sstream>

class Zombie {
	private:
		std::string name;
	public:
		Zombie();
		~Zombie();
		Zombie(std::string name);
		void announce();
        void setName(const std::string& name);
};

Zombie* zombieHorde(int N, std::string name);

#endif