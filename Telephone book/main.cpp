#include <stdlib.h>
#include <iostream>
#include "Telephone.h"

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





void doMenu(Telephone phone[], int& size) {
    int choice;
    int userNumber;
    int userAnswer;

    do {
        choice = menu();
        switch (choice) {
        case 1:
            Telephone t = Telephone::input();
            break;
        case 2:
            Telephone::printAllContacts(phone, size);
            break;
        case 3:
            Telephone::writeToFile(phone, 10);
            break;
        case 4:
            Telephone::readFromFile(phone, size);
            break;
        case 5:
            Telephone::printByFIO(phone, size);
            break;

        case 6:

            do {
                cout << "Iput number of worker to delete";
                cin >> userNumber;
            } while (userNumber <= 0);

            print(phone[userNumber - 1]);
            cout << "Are you sure that you want to delete this worker?(1=Yes,0=No):" << endl;
            cin >> userAnswer;
            if (userAnswer == 1)
            {
                Telephone::deleteContact(phone,size, userNumber);
            }
            else {
                cout << "Okay (-_-)" << endl;
            }

            break;
        case 7:
            cout << "Bye!" << endl;
            break;
        }
    } while (choice != 9);
}





int main()
{
   


	Telephone phone[10];
	Telephone t = Telephone::input();
	   phone[0] = t;
	 Telephone::writeToFile(phone,10);
	
	int size = 0;
     Telephone::readFromFile(phone, size);
	 t.printAllContacts( phone,size);





	//string s = "Bla bla";
	//const char* ss = copyLine(s);
	//cout << ss;

}