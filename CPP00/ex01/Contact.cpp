#include "PhoneBook.hpp"

Contact::Contact() {

}

Contact::~Contact() {

}

void Contact::setFirstName(std::string str) {
	this->firstName = str;
}

void Contact::setLastName(std::string str) {
	this->lastName = str;
}

void Contact::setNickname(std::string str) {
	this->nickname = str;
}

void Contact::setPhoneNumber(std::string str) {
	this->phoneNumber = str;
}

void Contact::setDarkestSecret(std::string str) {
	this->darkestSecret = str;
}

std::string& Contact::getFirstName() {
	return firstName;
}

std::string& Contact::getLastName() {
	return lastName;
}

std::string& Contact::getNickname() {
	return nickname;
}

std::string& Contact::getPhoneNumber() {
	return phoneNumber;
}

std::string& Contact::getDarkestSecret() {
	return darkestSecret;
}