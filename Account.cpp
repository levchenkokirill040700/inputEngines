

#include "Account.h"
#include <iostream>
#include <iomanip>
//
// Created by minhnhat on 10/17/2023.
//
using namespace std;
    string Account::getFirstName()const{return firstName;}
    string Account::getLastName()const{return lastName;}
    string Account::getAccUserName() const{return UserName;}
    void Account::setFirstName(string fn){firstName = fn;}
    void Account::setUsername(string usn){UserName = usn;}
    void Account::setBalance(float bl){balance = bl;}
    void Account::setLastName(string ln){lastName = ln;}
    float Account::getBalance() const {return balance;}
Account::Account(){
UserName = "NULL";
firstName = "NULL";
lastName = "NULL";
balance = 0;
}
Account::Account(string fname, string lname, string UserName, float balance)
    : UserName(UserName), firstName(fname), lastName(lname), balance(balance) 
{
}
void Account::Deposit(float amount){
    balance =  balance + amount;
     cout << "\n\nAmount deposited successfully. Updated balance: " << balance << endl;
}
void Account::Withdraw(float amount)
{
    if(balance - amount < 10) {
        cout << "Account's insufficient" << endl;
     return;
    }
    balance-=amount;
}

void Account::printInfo(){
    cout<< left << setw(12)<<" " <<setw(25) <<this->UserName << left <<std::setw(25) << lastName << std::setw(25) <<firstName << std::setw(25)<< balance<<endl;
}


 