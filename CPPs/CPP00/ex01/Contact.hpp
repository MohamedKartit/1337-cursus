#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

typedef struct ContactData
{
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
} ContactData;

class Contact {
	public:
		Contact();
		~Contact();
		void setContactData(ContactData contactData);
		ContactData getContactData();
	private:
		ContactData contactData;
};

#endif