#include <iostream>
#include "Bank.h"
using namespace std;
//
// Created by minhnhat on 10/13/2023.
//

void displayMenu();


int main() {
    Bank b;
int choice;
string tmp;
    do
    {
        system("cls");
       displayMenu();
        cin>>tmp;

       try {
            choice = stoi(tmp);
        } catch (const std::invalid_argument& e) {
            cout << "Invalid input. Please enter a number." << endl;
            system("pause");
            continue;
        }

        switch(choice)
        {
            case 1:
                    b.OpenAccount();
                system("pause");
                break;
            case 2:
                    b.BalanceEnquiry();
                system("pause");

                break;
            case 3:
                b.Deposit();
                system("pause");

                break;
            case 4:
               b.Withdraw();
                system("pause");

                break;
            case 5:
             b.CloseAccount();
                system("pause");
                break;
            case 6:
                b.ShowAllAccounts();
              system("pause");
                break;
            case 7:
               return 0;
            default:
                cout<<"\nEnter correct choice please!!";
                exit(0);
        }

    }while(choice!=7);
    return 0;
}
void displayMenu() {
    const int optionWidth = 33;
    cout<<"\n\n\n";
    
    cout<< left << setw(20)<<""<< setw(40)<< "***  Banking System Manager ***"<<setw(15)<<left<<""<<endl;

    cout << "+----------------------------------+----------------------------------+" << endl;
    cout << "| " << left << setw(optionWidth) << "1 Open an Account" << "| " << left << setw(optionWidth) << "5 Close an Account" << "|" << endl;
    cout << "+----------------------------------+----------------------------------+" << endl;
    cout << "| " << left << setw(optionWidth) << "2 Balance Enquiry" << "| " << left << setw(optionWidth) << "6 Show All Accounts" << "|" << endl;
    cout << "+----------------------------------+----------------------------------+" << endl;
    cout << "| " << left << setw(optionWidth) << "3 Deposit" << "| " << left << setw(optionWidth) << "7 Quit" << "|" << endl;
    cout << "+----------------------------------+----------------------------------+" << endl;
    cout << "| " << left << setw(optionWidth) << "4 Withdrawal" << "| " << left << setw(optionWidth) << " " << "|" << endl;
    cout << "+----------------------------------+----------------------------------+" << endl;
    cout << "Enter your choice: ";
}




