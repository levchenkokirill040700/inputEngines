//
// Created by minhnhat on 10/17/2023.
//
#ifndef BANKINGSYSTEM_ACCOUNT_H
#define BANKINGSYSTEM_ACCOUNT_H
#include<string>
#include<fstream>
#include<cstdlib>
#include<vector>
#include <iomanip>
#include<map>
#include <cctype>
// #include "HISTORY_TRANSITION_LIST.h"


using namespace std;


class Account
{
private:
    // HISTORY_TRANSITION_LIST acc_history_list;
    string UserName;
    string firstName;
    string lastName;
    float balance;
public:

    Account();
    Account(string fname,string lname,string UserName,float balance);
    string getFirstName()const;
    string getLastName()const;
    string getAccUserName() const;
    float getBalance() const;
    void setFirstName(string fn);
    void setUsername(string usn);
    void setBalance(float bl);
    void setLastName(string ln);
    void Deposit(float amount);
    void Withdraw(float amount);
    // void printAccountActivity(int &num);
    void printInfo();
   ~Account(){}
};



#endif //BANKINGSYSTEM_ACCOUNT_H
