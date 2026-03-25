#include "PhoneBook.hpp"
#include <cctype>

PhoneBook::PhoneBook() {

}

PhoneBook::~PhoneBook() {

}

Contact& PhoneBook::getContacts(int i) {
	return _contacts[i];
}

int& PhoneBook::getIndex() {
	return _index;
}

int checkInput(std::string input) {
	for (int i = 0; input[i]; i++)
		if (!std::isprint(input.at(i)))
			return 1;
	return 0;
}

std::string getInput(std::string str) {
	std::string input;

	std::cout << str << ": ";
	while (1) {
		std::getline(std::cin, input);
		if (std::cin.eof()) {
			std::cout << std::endl << "EOF detected. Exiting." << std::endl;
			break;
		}
		if (!input.empty() && !checkInput(input)) 
			break;
		std::cout << str << ": Wrong input. Try again: ";
	}
	return input;
}

Contact PhoneBook::createContact() {
	Contact newContact;

	newContact.setFirstName(getInput("First name"));
	newContact.setLastName(getInput("Last name"));
	newContact.setNickname(getInput("Nickname"));
	newContact.setPhoneNumber(getInput("Phone number"));
	newContact.setDarkestSecret(getInput("Darkest secret"));
	return newContact;
}

void PhoneBook::setContact() {
	this->_contacts[this->_index] = createContact();
}

void PhoneBook::setIndex() {
	int i = getIndex();
	i++;
	if (i == 8)
		this->_index = 0;
	else
		this->_index = i;
}

void PhoneBook::setIndex(int i) {
	this->_index = i;
}