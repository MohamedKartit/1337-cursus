#include "Contact.hpp"

Contact::Contact() {
}

Contact::~Contact() {
}

void Contact::setContactData(ContactData contactData) {
	this->contactData = contactData;
	this->contactData.firstName = contactData.firstName;
	this->contactData.lastName = contactData.lastName;
	this->contactData.nickname = contactData.nickname;
	this->contactData.phoneNumber = contactData.phoneNumber;
	this->contactData.darkestSecret = contactData.darkestSecret;
}

ContactData Contact::getContactData() {
	return (this->contactData);
}