#include "Telephone.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#define MAX_LEN 100
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
	return copyLine(buff);
}

char* check(string title) {
	return check(title, true);
}



Telephone Telephone::input()
{
	Telephone t = Telephone();
	t.FIO = check("first name");
	t.phoneHome = check("Home phone");
	t.phoneMobile = check("Mobile phone");
	t.phoneWork = check("Work phone");
	t.comments = check("Comments", false);
	return t;
}

void Telephone::print()
{
	cout << "    FIO:" << this->FIO;
	cout << "      Home Phone:" << this->phoneHome;
	cout << "      Work Phone:" << this->phoneWork;
	cout << "      Mobile Phone:" << this->phoneMobile;
	cout << "      Comments:" << this->comments;
}



//Worker* addWorker(Worker workers[], int& last)
//{
//	Worker* worker = new Worker;
//	inputNewWorker(worker);
//	workers[last] = *worker;
//	last++;
//	return worker;
//}

//void printAllWorkers(Worker workers[], int N) {
//	cout << endl << "Workers list:" << endl;
//	for (int i = 0; i < N; i++) {
//		cout << "  N:          " << i + 1 << endl;
//		printWorker(workers[i]);
//	}
//}


void Telephone::writeToFile(Telephone phone[], int size)
{
	ofstream outputFile("telephone_data.txt"); 
	if (!outputFile) 
		return;

	outputFile << size << endl;
	for (int i = 0; i < size; i++) {
		outputFile << phone[i].FIO << endl;
		outputFile << phone[i].phoneHome << endl;
		outputFile << phone[i].phoneMobile << endl;
		outputFile << phone[i].phoneWork << endl;
		outputFile << phone[i].comments << endl;
	}
	cout << "Success!" << endl;
}


char* copyLine(string line) {
	char* result = new char[line.length() + 1];
	strcpy_s(result, line.length() + 1, line.c_str());
	return result;
}

void Telephone::readFromFile(Telephone phone[], int &size) {
	//ifstream file("telephone_data.txt");

	//if (file.is_open()) {
	//	string line; 
	//	fgets(line, MAX_LEN, stdin);
	//	int count = atoi(line);

	//	for (int i = 0; i < count; i++) {
	//		Telephone* t = new Telephone;
	//		fgets(line, MAX_LEN, stdin);
	//		t->FIO = copyLine(line);
	//		fgets(line, MAX_LEN, stdin);
	//		t->phoneHome = copyLine(line);
	//		fgets(line, MAX_LEN, stdin);
	//		t->phoneMobile = copyLine(line);
	//		fgets(line, MAX_LEN, stdin);
	//		t->phoneWork = copyLine(line);
	//		fgets(line, MAX_LEN, stdin);
	//		t->comments = copyLine(line);
	//		phone[i] = *t;
	//	}
	//	size = count;
	//	file.close();
	//}
	//else {
	//	cout << "Oops!" << std::endl;
	//}
}