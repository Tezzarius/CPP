#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <sstream>

class Zombie {
	private:
		std::string	_name;

	public:
		Zombie();
		Zombie(std::string name);
		Zombie(const Zombie &other);
		Zombie &operator=(const Zombie &other);
		~Zombie();
		
		void	announce();
        void	setName(const std::string& name);
};

Zombie*	zombieHorde(int N, std::string name);

#endif