#ifndef _CONTACT_H_
#define _CONTACT_H_

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;


class Contact {
public:
	Contact();

	const string& getFirstName();
	void setFirstName(const string firstname);

	const string& getLastName();
	void setLastName(const string lastname);

	const string& getNickName();
	void setNickName(const string nickname);

	const string& getPhoneNumber();
	void setPhoneNumber(const string phonenumber);

	void setDarkestScret(const string darkestscret);

private:
	string _firstName;
	string _lastName;
	string _nickname;
	string _phoneNumber;
	string _darkestSecret;


};







#endif
