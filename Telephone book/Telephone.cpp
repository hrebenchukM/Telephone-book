#include "Telephone.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include "PhoneBook.h"
using namespace std;


char* check(string title, bool checkEmpty) {
	string buff = "";
	while (true) {
		cout << "Enter worker " << title << ": ";
		getline(cin >> ws, buff);

		if (buff.empty()) {
			cout << "Wrong input! Cannot be empty \n";
		}
		else
			break;
	}
	return PhoneBook::copyLine(buff);
}

char* check(string title) {
	return check(title, true);
}



Contact Contact::input2()
{
	Contact t;
	t.FIO = check("first name");
	t.phoneHome = check("Home phone");
	t.phoneMobile = check("Mobile phone");
	t.phoneWork = check("Work phone");
	t.comments = check("Comments", false);
	return t;
}
void Contact::print()
{
	cout << "    FIO:" << this->FIO << endl;
	cout << "      Home Phone:" << this->phoneHome << endl;
	cout << "      Work Phone:" << this->phoneWork << endl;
	cout << "      Mobile Phone:" << this->phoneMobile << endl;
	cout << "      Comments:" << this->comments << endl;
}

void Contact::input()
{
	this->FIO = check("first name");
	this->phoneHome = check("Home phone");
	this->phoneMobile = check("Mobile phone");
	this->phoneWork = check("Work phone");
	this->comments = check("Comments", false);
}



