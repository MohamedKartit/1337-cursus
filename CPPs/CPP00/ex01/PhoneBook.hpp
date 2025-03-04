#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	public:
		PhoneBook();
		~PhoneBook();
		void add(Contact contact);
		void search(int index);
		int getContactCount();
		int print();
	private:
		Contact contacts[8];
		int contactCount;
};


std::string	trimSpaces(std::string str);
void		printInvalid(std::string command);
int			whitespaces(std::string str);
bool		checkPrintable(std::string command);
int			NumberChecker(std::string &input);

#endif