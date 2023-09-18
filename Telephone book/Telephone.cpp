#include "Telephone.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include "PhoneBook.h"
using namespace std;

/*
char* copyLine(string line) {
	char* result = new char[line.length() + 1];
	strcpy_s(result, line.length() + 1, line.c_str());
	return result;
} */


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



Contact Contact::input()
{
	Contact t = Contact();
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
/*
Contact Contact::addContact(Contact contacts[], int& size) {
	Contact phone = phone.input();
	contacts[size] = phone;
	phone.print();
	size++;
	return phone;
}*/




/*
void Contact::printAllContacts(Contact contacts[], int size) {
	cout << endl << "Contacts list:" << endl;
	for (int i = 0; i < size; i++) {
		cout << "  N:          " << i + 1 << endl;
		contacts[i].print();
	}
}*/

/*
void Contact::writeToFile(Contact contacts[], int size)
{
	ofstream outputFile("telephone_data.txt"); 
	if (!outputFile) 
		return;

	outputFile << size << endl;
	for (int i = 0; i < size; i++) {
		outputFile << contacts[i].FIO << endl;
		outputFile << contacts[i].phoneHome << endl;
		outputFile << contacts[i].phoneMobile << endl;
		outputFile << contacts[i].phoneWork << endl;
		outputFile << contacts[i].comments << endl;
	}
	cout << "Success!" << endl;
}

*/

/*
void Contact::readFromFile(Contact contacts[], int &size) {
	ifstream file("telephone_data.txt");

	if (file.is_open()) {

		string line;
		getline(file, line);
		int count = stoi(line);

		for (int i = 0; i < count; i++) {
			Contact* t = new Contact;
			getline(file, line);
			t->FIO = copyLine(line);
			getline(file, line);
			t->phoneHome = copyLine(line);
			getline(file, line);
			t->phoneMobile = copyLine(line);
			getline(file, line);
			t->phoneWork = copyLine(line);
			getline(file, line);
			t->comments = copyLine(line);
			contacts[i] = *t;
		}
		size = count;
		file.close();
	}
	else {
		cout << "Oops!" << std::endl;
	}
}*/
/*
void Contact::deleteContact(Contact contacts[], int& size, int userNumber)

{
	int index = userNumber - 1;
	for (int i = index; i < size - 1; i++) {
		contacts[i] = contacts[i + 1];
	}
	size--;

}*/
/*void Contact::doDelete(Contact contacts[], int& size)
{   
	int userNumber;
	int userAnswer;
	do {
		
		     cout << "Input number of worker to delete";
		     cin >> userNumber;
		 } while (userNumber <= 0);

		 (contacts[userNumber - 1]).print();
		 cout << "are you sure that you want to delete this worker?(1=yes,0=no):" << endl;
		 cin >> userAnswer;
		 if (userAnswer == 1)
		 {
		     deleteContact(contacts, size, userNumber);
		 }
		 else {
		     cout << "okay (-_-)" << endl;
		 }
}

*/


/*int Contact::searchByFIO(Contact contacts[], int size, string nameKey) {
	for (int i = 0; i < size; i++) {

		if (string(contacts[i].FIO).find(nameKey) !=std::string::npos) 
	{
			return i;
	}
	}
	return -1;
}


void Contact::printByFIO(Contact contacts[], int& size) {
	string nameKey;
	cout << "Enter the last name to find:";
	getline(cin >> ws, nameKey,
		'\n'); 
	int index = searchByFIO(contacts, size, nameKey);
	if (index >= 0) {
		contacts[index].print();
	}
	else {
		cout << "No such worker found" << endl;
	}
}
*/
