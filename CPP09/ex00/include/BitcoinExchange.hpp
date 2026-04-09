#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <cstdlib>
# include <iomanip>
# include <map>
# include <climits>

# ifndef VERBOSE
#  define VERBOSE 0
# endif

int	mappingData(std::map<std::string, double> &data);
int bitcoinExchange(std::map<std::string, double> &data, std::ifstream &fd);

#endif