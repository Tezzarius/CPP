#include <iostream>
#include <string>
#include <fstream>

void searchAndReplace(std::string str, const std::string &s1, const std::string &s2, std::ofstream &outfile) {
	if (s1.empty()) {
		outfile << str << std::endl;
		return;
	}
	std::size_t pos = 0;
	while ((pos = str.find(s1, pos)) != std::string::npos) {
		str.erase(pos, s1.length());
		str.insert(pos, s2);
		pos += s2.length();
	}
	outfile << str << std::endl;
}

int main(int ac, char **av) {
	if (ac != 4) {
		std::cout << "Error:" << std::endl << "Wrong amount of arguments" << std::endl;
		return 1;
	}
	std::ifstream fd(av[1]);
	if (!fd.is_open()) {
		std::cout << "Error:" << std::endl << "Can't open file" << std::endl;
		return 1;
	}
	std::string outfilename = std::string(av[1]) + ".replace";
	std::ofstream outfile(outfilename.c_str());
	if (!outfile.is_open()) {
		std::cout << "Error:" << std::endl << "Can't create output file" << std::endl;
		fd.close();
		return 1;
	}
	std::string str;
	while (std::getline(fd, str)) {
		searchAndReplace(str, av[2], av[3], outfile);
	}
	outfile.close();
	fd.close();
}