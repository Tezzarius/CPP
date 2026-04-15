#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T &cont, int val) {
	typename T::iterator it = std::find(cont.begin(), cont.end(), val);
	if (it == cont.end()) {
		throw std::runtime_error("No occurrence found!");
	}
	return it;
}

#endif