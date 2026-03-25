#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon {
private:
	std::string _type;
public:
	Weapon();
	Weapon(const std::string &type);
	Weapon(const Weapon &other);
	Weapon &operator=(const Weapon &other);
	~Weapon();

	std::string const &getType();
	void setType(const std::string &type);
};

#endif