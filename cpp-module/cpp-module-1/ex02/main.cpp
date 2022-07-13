#include <iostream>

using std::string;
using std::cout;

int main()
{
	const string str("HI THIS IS BRAIN");

	const string* stringPTR = &str;
	const string& stringREF = str;

	cout << "STR: " << &str << std::endl;
	cout << "strPTR: " << stringPTR << std::endl;
	cout << "strREF: " << &stringREF << std::endl;

	cout << std::endl;

	cout << "Value of str: " << str << std::endl;
	cout << "Value of strPTR: " << *stringPTR << std::endl;
	cout << "Value of strREF: " << stringREF << std::endl;

}