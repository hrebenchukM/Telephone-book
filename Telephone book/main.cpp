#include <stdlib.h>
#include <iostream>
#include "Telephone.h"
#include "PhoneBook.h"

using namespace std;

int menu() {
    cout << endl;
    cout << "1.Add new Contact:" << endl;
    cout << "2.Print Contacts:" << endl;
    cout << "3.Write to file:" << endl;
    cout << "4.Read from file:" << endl;
    cout << "5.Find by FIO:" << endl;
    cout << "6.Delete worker:" << endl;
    cout << "7.EXIT:" << endl;

    int choice;
    do {
        cout << "Enter your choice:";
        cin >> choice;
    } while (choice < 1 || choice > 7);
    return choice;
}





//void doMenu(Contact phones[], int& size) {
//    int choice;
//    int userNumber;
//    int userAnswer;
//
//    do {
//        choice = menu();
//        switch (choice) {
//        case 1:
//            Contact::addContact(phones, size);
//            break;
//        case 2:
//            Contact::printAllContacts(phones, size);
//            break;
//        case 3:
//            Contact::writeToFile(phones, size);
//            break;
//        case 4:
//            Contact::readFromFile(phones, size);
//            break;
//        case 5:
//            Contact::printByFIO(phones, size);
//            break;
//
//        case 6:
//
//            do {
//                cout << "Iput number of worker to delete";
//                cin >> userNumber;
//            } while (userNumber <= 0);
//
//            (phones[userNumber - 1]).print();
//            cout << "Are you sure that you want to delete this worker?(1=Yes,0=No):" << endl;
//            cin >> userAnswer;
//            if (userAnswer == 1)
//            {
//                Contact::deleteContact(phones,size, userNumber);
//            }
//            else {
//                cout << "Okay (-_-)" << endl;
//            }
//
//            break;
//        case 7:
//            cout << "Bye!" << endl;
//            break;
//        }
//    } while (choice != 9);
//}


void doMenu(PhoneBook phoneBook) {
    int choice;
    

    do {
        choice = menu();
        switch (choice) {
        case 1:
            phoneBook.addContact();
            break;
        case 2:
            phoneBook.printAllContacts();
            break;
        case 3:
            phoneBook.writeToFile();
            break;
        case 4:
            phoneBook.readFromFile();
            break;
        case 5:
            phoneBook.printByFIO();
            break;

        case 6:
            phoneBook.deleteContact();
           // phoneBook.doDelete();
            
            break;
        case 7:
            cout << "Bye!" << endl;
            break;
        }
    } while (choice != 9);
}



int main()
{
   


	//Telephone phone[10];
	//Telephone t = Telephone::input();
	 //  phone[0] = t;
	 //Telephone::writeToFile(phone,10);
	//
	///int size = 0;
    // Telephone::readFromFile(phone, size);
	 //t.printAllContacts( phone,size);

    //const int N = 10;
    //int size = 0;
    //Contact phones[N];
    
    PhoneBook phoneBook = PhoneBook();
    doMenu(phoneBook);



}