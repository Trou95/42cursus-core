#include "PhoneBook.h"


PhoneBook::PhoneBook() {
	index =
	size = 0;
}

void PhoneBook::add(const string firstname, const string lastname, const string nickname, const string phonenumber, const string darkestscreet) {
	if (firstname.empty() || lastname.empty() || nickname.empty() || phonenumber.empty() || darkestscreet.empty())
	{
		cout << "Empty field" << std::endl;
		return;
	}
	if (index == 8)
		index = 0;
	if (size < 8)
		size++;
	contacts[index].setFirstName(firstname);
	contacts[index].setLastName(lastname);
	contacts[index].setNickName(nickname);
	contacts[index].setPhoneNumber(phonenumber);
	contacts[index++].setDarkestScret(darkestscreet);
}

void PhoneBook::getContactByID(size_t index) {
	if (index < size)
		cout << index << "| " << wordCheck(contacts[index].getFirstName()) << "| " << wordCheck(contacts[index].getLastName()) << wordCheck(contacts[index].getNickName()) << "| " << wordCheck(contacts[index].getPhoneNumber()) << endl;
}

void PhoneBook::getContacts() {
	for (int i = 0; i < size; i++)
		getContactByID(i);
}

void PhoneBook::wordCheck(const string& text) {
	size_t len = text.length();
	if (len > 10) {
		for (int i = 0; i < 9; i++)
			cout << static_cast<char>(text[i]);
		cout << ".";
	}
	else
	{
		for (int i = 10 - len; i; i--)
			cout << " ";
		cout << text.c_str() << endl;
	}
}