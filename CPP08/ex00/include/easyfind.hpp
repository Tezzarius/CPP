#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &cont, int val);

# include "easyfind.tpp"

#endif
