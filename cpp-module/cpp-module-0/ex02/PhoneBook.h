#ifndef _PHONEBOOK_H_
#define _PHONEBOOK_H_

#include "Contact.h"

class PhoneBook {
public:
	PhoneBook();

	void add(const string firstname, const string lastname, const string nickname, const string phonenumber, const string darkestscret);
	void getContactByID(size_t index);
	void getContacts();
private:
	size_t index;
	size_t size;

	Contact contacts[8];
	void wordCheck(const string& text);
};

#endif
