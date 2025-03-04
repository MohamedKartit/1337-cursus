// Description: PhoneBook class implementation.
#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() {
	contactCount = 0;
}

PhoneBook::~PhoneBook() {
}

std::string LengthCheck(std::string str)
{
	if (str.length() > 10)
	{
		str.resize(9);
		str.append(".");
	}
	return (str);
}

void PhoneBook::add(Contact contact) {
	if (contactCount < 8) {
		contacts[contactCount] = contact;
		contactCount++;
	}
	else {
		for (int i = 0; i < 7; i++) {
			contacts[i] = contacts[i + 1];
		}
		contacts[7] = contact;
	}
}

void PhoneBook::search(int index) {
	ContactData contactData = contacts[index - 1].getContactData();
	std::cout << "First Name: " << contactData.firstName << std::endl;
	std::cout << "Last Name: " << contactData.lastName << std::endl;
	std::cout << "Nickname: " << contactData.nickname << std::endl;
	std::cout << "Phone Number: " << contactData.phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << contactData.darkestSecret << std::endl;
}

int PhoneBook::getContactCount() {
	return (contactCount);
}


int PhoneBook::print() {
	if (contactCount == 0) {
		std::cout << "No contacts in the phonebook" << std::endl;
		return (1);
	}
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < contactCount; i++) {
		std::cout << std::setw(10) << i + 1 << "|";
		std::cout << std::setw(10) << LengthCheck(contacts[i].getContactData().firstName) << "|";
		std::cout << std::setw(10) << LengthCheck(contacts[i].getContactData().lastName) << "|";
		std::cout << std::setw(10) << LengthCheck(contacts[i].getContactData().nickname) << std::endl;
	}
	return (0);
}