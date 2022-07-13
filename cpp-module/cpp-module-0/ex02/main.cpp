#include <iostream>

#include "PhoneBook.h"

using namespace std;

int main(int ac, char** av)
{
	PhoneBook phonebook;
	string input;

	while (cin >> input)
	{
		cout << "Which process do you want ADD | SEARCH | EXIT" << endl;
		if (input == "ADD")
		{
			string firstname;
			string lastname;
			string nickname;
			string phonenumber;
			string darkestsecret;

			cout << "Enter Firstname: ";
			cin >> firstname;
			cout << "Enter Lastname: ";
			cin >> lastname;
			cout << "Enter nickname: ";
			cin >> nickname;
			cout << "Enter Phonenumber: ";
			cin >> phonenumber;
			cout << "Enter Darkest Secret: ";
			cin >> darkestsecret;
			phonebook.add(firstname, lastname, nickname, phonenumber, darkestsecret);
		}
		else if (input == "SEARCH")
		{
			size_t index;
			phonebook.getContacts();
			cout << "Enter index: ";
			cin >> index;
			phonebook.getContactByID(index);
		}
		else if (input == "EXIT")
			exit(0);
	}
}