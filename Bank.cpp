//
// Created by minhnhat on 10/18/2023.
//
#include <iostream>
#include "Bank.h"
using namespace std;
void printTitle()
{
    cout << left << setw(12) << "Index" << setw(25) << "Username" << left << std::setw(25) << "Lastname" << std::setw(25) << "FirstName" << std::setw(25) << "Balance";

    cout << "\n"
         << left << setw(110) << "________________________________________________________________________________________________________" << endl;
}
void Bank::parseAccountInfo(const string &line)
{
    string username, firstname, lastname;
    float balance;

    istringstream iss(line);
    getline(iss, username, ',');
    getline(iss, firstname, ',');
    getline(iss, lastname, ',');
    iss >> balance;  
    if (!username.empty() && !firstname.empty() && !lastname.empty())
    {
        auto itr = accounts.find(username);
        if(itr!=accounts.end()) return;
        Account account(firstname, lastname, username, balance);
        sorted_accounts.insert(pair<float, Account>(account.getBalance(), account));
        accounts.insert(pair<string, Account>(account.getAccUserName(), account));
    }
}
Bank::Bank()
{
    ifstream infile;
    isSorted = false;
    infile.open("data.txt");
    if (!infile.is_open())
    {
        cout << "Error in Opening! File Not Found!!" << endl;
        return;
    }
    string input;
    while (getline(infile, input))
    {
        if (!input.empty())
        {
            parseAccountInfo(input);
        }
    }
    infile.close();
}

bool isNumber(const string &s)
{
    for (char const &ch : s)
    {
        if (std::isdigit(ch) == 0)
            return false;
    }
    return true;
}
void Bank::OpenAccount()
{
    string fname, lname;
    string UserName;
    float balance;
    string balance_tmp;
    float amount;
    cout << "Enter First Name: ";
    cin >> fname;
    cout << "Enter Last Name: ";
    cin >> lname;
    cout << "Create UserName for account: ";
    cin >> UserName;
    auto it = accounts.find(UserName);
    while (it != accounts.end() && accounts.size() > 1)
    {
        cout << "This username exists, try another one: ";
        cin >> UserName;
        it = accounts.find(UserName);
    }

    cout << "Enter initial Balance: ";
    cin >> balance_tmp;
    while (!isNumber(balance_tmp))
    {
        cout << "Please Enter a Number for initial Balance: ";
        cin >> balance_tmp;
    }
    balance = stoi(balance_tmp);

    ofstream outfile;
    Account newAccount(fname, lname, UserName, balance);

    sorted_accounts.insert(pair<float, Account>(newAccount.getBalance(), newAccount));
    accounts.insert(pair<string, Account>(newAccount.getAccUserName(), newAccount));

    outfile.open("data.txt", ios::app);

    if (!outfile.is_open())
    {
        cout << "Error in Opening File!" << endl;
        return;
    }
    outfile << UserName << ';';
    outfile << fname << ';';
    outfile << lname << ';';
    outfile << balance << " " << endl;
    outfile.close();

    cout << "\n\n"
         << endl;
    printTitle();
    newAccount.printInfo();

    cout << "\n\n";
    cout << endl
         << "ACCOUNT HAS BEEN INITIALIZED !!!" << endl;
}
void Bank::BalanceEnquiry()
{
    string UserName;
    cout << "Enter User Name:";
    cin >> UserName;
    map<string, Account>::iterator itr = accounts.find(UserName);
    if (itr == accounts.end())
    {
        cout << "There is no username " << UserName << " .PLease try again!" << endl;
        return;
    }
    cout << "\n\n\n";
    cout << left << setw(40) << "" << setw(40) << "--- Your Account Details ---" << setw(15) << left << "" << endl;
    cout << "\n\n";
    printTitle();
    itr->second.printInfo();
    cout << "\n\n\n";
}
void Bank::Deposit()
{
    string UserName;
    float amount;
    cout << "Enter User Name:";
    cin >> UserName;

    map<string, Account>::iterator itr = accounts.find(UserName);
    if (itr == accounts.end())
    {
        cout << "Username " << UserName << " does not exist" << endl;
        return;
    }

    while (true)
    {
        cout << "Enter Deposit Amount:";
        string amount_str;
        cin >> amount_str;

        if (isNumber(amount_str))
        {
            amount = stof(amount_str);
            break;
        }
        else
        {
            cout << "Invalid input. Please enter a valid numeric value." << endl;
        }
    }

    itr->second.Deposit(amount);
cout<<"\n\n\n";
    printTitle();
    itr->second.printInfo();
    cout<<"\n\n\n";
}

void Bank::Withdraw()
{
    string UserName;
    float amount;
    cout << "Enter User Name:";
    cin >> UserName;

    map<string, Account>::iterator itr = accounts.find(UserName);
    if (itr == accounts.end())
    {
        cout << "Username " << UserName << " does not exist" << endl;
        return;
    }

    while (true)
    {
        cout << "Enter Withdrawal Amount:";
        string amount_str;
        cin >> amount_str;

        if (isNumber(amount_str))
        {
            amount = stof(amount_str);
            break;
        }
        else
        {
            cout << "Invalid input. Please enter a valid numeric value." << endl;
        }
    }

    if (itr->second.getBalance() < amount)
    {
        cout << "Insufficient balance for withdrawal" << endl;
        return;
    }

    itr->second.Withdraw(amount);
    cout<<"\n\n\n";
    cout << "Amount Withdrawn" << endl;
    printTitle();
    itr->second.printInfo();
    cout<<"\n\n\n";
}
void Bank::CloseAccount()
{
    string us;

    cout << "Enter User Name:";
    cin >> us;

    map<string, Account>::iterator itr = accounts.find(us);
    if (itr == accounts.end())
    {
        cout << us << "do not exist" << endl;
        return;
    }
    accounts.erase(us);
    cout << "Account deleted successfully!" << endl;
}

void Bank::ShowAllAccounts()
{
    int count = 1;
    if (accounts.empty())
    {
        cout << "There's no account to show" << endl;
        return;
    }
    map<string, Account>::iterator itr;
    cout << "\n\n\n\n";
    printTitle();
    for (itr = accounts.begin(); itr != accounts.end(); itr++)
    {
        if (itr->second.getAccUserName().empty())
            continue;

        cout << left << setw(12) << count << setw(25) << itr->second.getAccUserName() << left << std::setw(25) << itr->second.getLastName() << std::setw(25) << itr->second.getFirstName() << std::setw(25) << itr->second.getBalance();
        cout << "\n"
             << left << setw(110) << "________________________________________________________________________________________________________" << endl;

        count++;
    }

    cout << "\n\n\n";
   
  while(true){
     string choice;
   
    cout<<"Do you want to sort the account list's balance: "<<endl;
    cout << "1.Ascending order."<<endl;
    cout << "2.Descending order."<<endl;
     cout <<"3.Return back."<<endl;
     cout<<"Enter you option: ";
    cin >> choice;

    system("cls");
   if (choice== "1")
   {
    ShowTheAllSortedAccountsByBalanceInAscendingOrder();
   } else if( choice== "2"){
    ShowTheAllSortedAccountsByBalanceInDescendingOrder();
   } else if(choice == "3"){ 
     return;
   } else{
   cout<<"Please choose one of the options!.\n\n";
   system("pause");
   }
   

       
  }
   
}
void Bank::clearSorted()
{
    sorted_accounts.clear();
}



void Bank::ShowTheAllSortedAccountsByBalanceInAscendingOrder()
{
    int count = 1;
    if (sorted_accounts.empty())
    {
        cout << "There's no account to sort" << endl;
        return;
    }
    multimap<float, Account>::iterator itr;
    cout << "\n\n\n\n";
    printTitle();
    for (itr = sorted_accounts.begin(); itr != sorted_accounts.end(); itr++)
    {
        if (itr->second.getAccUserName().empty())
            continue;

        cout << left << setw(12) << count << setw(25) << itr->second.getAccUserName() << left << std::setw(25) << itr->second.getLastName() << std::setw(25) << itr->second.getFirstName() << std::setw(25) << itr->first;
        cout << "\n"
             << left << setw(110) << "________________________________________________________________________________________________________" << endl;

        count++;
    }
     
}
void Bank::ShowTheAllSortedAccountsByBalanceInDescendingOrder(){

    int count = 1;
    if (sorted_accounts.empty())
    {
        cout << "There's no account to sort" << endl;
        return;
    }
 
    cout << "\n\n\n\n";
    printTitle();
    for (auto itr = sorted_accounts.rbegin(); itr != sorted_accounts.rend(); itr++)
    {
        if (itr->second.getAccUserName().empty())
            continue;

        cout << left << setw(12) << count << setw(25) << itr->second.getAccUserName() << left << std::setw(25) << itr->second.getLastName() << std::setw(25) << itr->second.getFirstName() << std::setw(25) << itr->first;
        cout << "\n"
             << left << setw(110) << "________________________________________________________________________________________________________" << endl;

        count++;
    }

}

Bank::~Bank()
{
    ofstream outfile;
    outfile.open("data.txt", ios::app);

    if (!outfile.is_open())
    {
        cout << "Error in Opening File!" << endl;
        return;
    }

    map<string, Account>::iterator itr;
    for (itr = accounts.begin(); itr != accounts.end(); itr++)
    {
        if (itr->second.getAccUserName().empty() || itr->second.getFirstName().empty() || itr->second.getLastName().empty())
        {
            continue;
        }
        outfile << itr->second.getAccUserName() << ',';
        outfile << itr->second.getFirstName() << ',';
        outfile << itr->second.getLastName() << ',';
        outfile << itr->second.getBalance() << " " << '\n';
    }
    outfile.flush();
    outfile.close();
}
