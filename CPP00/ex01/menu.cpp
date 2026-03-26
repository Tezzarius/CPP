#include "PhoneBook.hpp"

void styleOutput(std::string str) {
	int len = str.length();

	if (len < 10) {
		for (int i = 0; i + len < 10; i++) {
			std::cout << " ";
		}
		std::cout << str;
	}
	else if (len == 10) {
		std::cout << str;
	}
	else if (len > 10) {
		for (int i = 0; i < 9; i++) {
			std::cout << str.at(i);
		}
		std::cout << ".";
	}
}

void listContacts(PhoneBook &book) {
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < 8; i++) {
		Contact con = book.getContacts(i);
		std::cout << "|         " << i + 1 << "|";
		styleOutput(con.getFirstName());
		std::cout << "|";
		styleOutput(con.getLastName());
		std::cout << "|";
		styleOutput(con.getNickname());
		std::cout << "|" << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
	}
	std::cout << std::endl;
}

void searchContact(PhoneBook &book) {
	std::string input;
	while (true) {
		std::cout << "Please enter the index you are looking for: ";
		if (!std::getline(std::cin, input)) {
			break;
		}
		std::cout << std::endl;
		if (input.length() != 1 || input.at(0) < '1' || input.at(0) > '8') {
			std::cout << "Wrong input, index isn't aviable" << std::endl;
			continue;
		}
		else {
			int i = input.at(0) - '0';
			Contact con = book.getContacts(i - 1);
			std::cout << "first name: " << con.getFirstName() << std::endl;
			std::cout << "last name: " << con.getLastName() << std::endl;
			std::cout << "nickname: " << con.getNickname() << std::endl;
			std::cout << "phone number: " << con.getPhoneNumber() <<std::endl;
			std::cout << "darkest secret: " << con.getDarkestSecret() << std::endl;
			break;
		}
	}
}

void phoneBookMenu(PhoneBook &book) {
	std::string input;
	while (true) {
		std::cout << "Select operation ADD, SEARCH or EXIT: ";
		if (!std::getline(std::cin, input)) {
			std::cout << std::endl << "EOF detected. Exiting." << std::endl;
			break;
		}
		std::cout << std::endl;
		if (!input.compare("ADD")) {
			book.setIndex();
			book.setContact();
		}
		else if (!input.compare("SEARCH")) {
			listContacts(book);
			searchContact(book);
			if (std::cin.eof()) {
				std::cout << std::endl << "EOF detected. Exiting." << std::endl;
				break;
			}
		}
		else if (!input.compare("EXIT")) {
			break;
		}
		else {
			std::cout << "Invalid input, try again" << std::endl;
		}
		std::cout << std::endl;
	}
}