
#ifndef BANKINGSYSTEM_BANK_H
#define BANKINGSYSTEM_BANK_H
#include "Account.h"
#include <sstream>
#include<vector>
#include <typeinfo>
#include<algorithm>
//
// Created by minhnhat on 10/18/2023.
//
bool isNumber(const string& s);
void printTitle();
class Bank
{
private:
    map<string,Account> accounts;
    multimap<float,Account> sorted_accounts; 
    bool isSorted;
public:
    Bank();
    void  clearSorted();
    void OpenAccount();
    void BalanceEnquiry();
    void Deposit();
    void Withdraw();
    void CloseAccount();
    void ShowAllAccounts();
    void parseAccountInfo(const string& line);
    void ShowTheAllSortedAccountsByBalanceInAscendingOrder();
     void ShowTheAllSortedAccountsByBalanceInDescendingOrder();
    // void ShowTransitionHistory();
    ~Bank();
};
#endif //BANKINGSYSTEM_BANK_H

