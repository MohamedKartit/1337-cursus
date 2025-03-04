#include "PhoneBook.hpp"

bool checkIsNumber(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}

int StringToInt(std::string str)
{
	int num = 0;
	if (!checkIsNumber(str))
		return (-1);
	for (size_t i = 0; i < str.length(); i++)
		num = num * 10 + (str[i] - '0');
	return (num);
}

int SearchContact(PhoneBook *phoneBook)
{
	std::string search;
	int index;

	if (phoneBook->print())
		return (1);
	std::cout << "Enter index: ";
	std::getline(std::cin, search);
	if (std::cin.eof())
		return (0);
	if (search == "" || whitespaces(search) || !checkPrintable(search))
	{
		std::cout << "Invalid index: try one of the available indexes" << std::endl;
		return (1);
	}
	index = StringToInt(search);
	if (index < 1 || (index > phoneBook->getContactCount()))
	{
		std::cout << "invalid index: try one of the available indexes" << std::endl;
		return (1);
	}
	phoneBook->search(index);
	return (1);
}

int InsertData(std::string &input, std::string prompt)
{
	std::cout << prompt;
	std::getline(std::cin, input);
	if (std::cin.eof())
		return (0);
	if (input == "" || whitespaces(input) || !checkPrintable(input))
	{
		std::cout << "Invalid input" << std::endl;
		return (InsertData(input, prompt));
	}
	if (prompt == "Enter phone number: ")
	{
		if (!NumberChecker(input))
		{
			std::cout << "Invalid phone number" << std::endl;
			return (InsertData(input, prompt));
		}
	}
	input = trimSpaces(input);
	return (1);
}

int AddContact(PhoneBook *phoneBook)
{
	Contact contact;
	ContactData contactData;

	if (!InsertData(contactData.firstName, "Enter first name: "))
		return (0);
	if (!InsertData(contactData.lastName, "Enter last name: "))
		return (0);
	if (!InsertData(contactData.nickname, "Enter nickname: "))
		return (0);
	if (!InsertData(contactData.phoneNumber, "Enter phone number: "))
		return (0);
	if (!InsertData(contactData.darkestSecret, "Enter darkest secret: "))
		return (0);
	contact.setContactData(contactData);
	phoneBook->add(contact);
	return (1);
}

int PromptLoop(PhoneBook *phoneBook)
{
	std::string command;

	std::cout  << "enter your command: ";
	std::getline(std::cin, command);
	if (std::cin.eof())
		return (0);
	command = trimSpaces(command);
	if (command == "EXIT")
	{
		std::cout << "Exiting..." << std::endl;
		return (0);
	}
	else if (command == "SEARCH")
		return (SearchContact(phoneBook));
	else if (command == "ADD")
		return (AddContact(phoneBook));
	else if (command == "")
		return (1);
	return (printInvalid(command), 1);
}

int main()
{
	PhoneBook phoneBook;
	while (PromptLoop(&phoneBook))
		;
	return 0;
}