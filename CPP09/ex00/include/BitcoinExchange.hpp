#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <cstdlib>
# include <iomanip>
# include <map>

# ifndef VERBOSE
#  define VERBOSE 0
# endif

class BitcoinExchange {
	private:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		static int validateDate(std::string &str, double &value);

	public:
		static int mappingData(std::map<std::string, double> &data);
		static int exchange(std::map<std::string, double> &data, std::ifstream &fd);
};


#endif