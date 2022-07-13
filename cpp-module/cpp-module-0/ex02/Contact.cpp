#include "Contact.h"

const string& Contact::getFirstName() {
	return _firstName;
}

void Contact::setFirstName(const string firstname) {
	_firstName = firstname;
}

const string& Contact::getLastName() {
	return _lastName;
}

void Contact::setLastName(const string lastname) {
	_lastName = lastname;
}

const string& Contact::getLastName() {
	return _nickname;
}

void Contact::setNickName(const string nickname) {
	_nickname = nickname;
}

const string& Contact::getPhoneNumber() {
	return _phoneNumber;
}

void Contact::setPhoneNumber(const string phonenunber) {
	_phoneNumber = phonenunber;
}

void Contact::setDarkestScret(const string darkestscret) {
	_darkestSecret = darkestscret;
}