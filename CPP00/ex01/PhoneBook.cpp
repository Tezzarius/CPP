#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {

}

PhoneBook::~PhoneBook() {

}

Contact& PhoneBook::getContacts(int i) {
	return contacts[i];
}

int& PhoneBook::getIndex() {
	return index;
}

std::string getInput(std::string str) {
	std::string input;

	std::cout << str << ": ";
	while (1) {
		std::getline(std::cin, input);
		if (!input.empty())
			break;
		std::cout << str << " can't be empty. Try again: ";
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
	this->contacts[this->index] = createContact();
}

void PhoneBook::setIndex() {
	int i = getIndex();
	i++;
	if (i == 8)
		this->index = 0;
	else
		this->index = i;
}

void PhoneBook::setIndex(int i) {
	this->index = i;
}