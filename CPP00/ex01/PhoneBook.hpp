#ifndef PHONEBOOK_CPP
# define PHONEBOOK_CPP

# include <iostream>
# include <string>
# include "Contact.hpp"

class PhoneBook {
	private:
		Contact _contacts[8];
		int		_index;
	public:
		PhoneBook();
		~PhoneBook();
		void setIndex();
		void setIndex(int i);
		void setContact();
		int& getIndex();
		Contact& getContacts(int i);
		Contact createContact();
};

void phoneBookMenu(PhoneBook &book);

#endif