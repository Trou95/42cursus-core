#include <iostream>
#include "Account.h"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


Account::Account(int initial_deposit) {
    _nbDeposits =
     _nbWithdrawals = 0;
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    cout << "index:" << _nbAccounts++ << ";ammount:" << initial_deposit << ";created" << endl;
}

int Account::getNbAccounts() {
    return _nbAccounts;
}

int Account::getTotalAmount() {
    return _totalAmount;
}

int Account::getNbDeposits() {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals() {
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos() {
    _displayTimestamp();
    cout << "accounts:" << _nbAccounts << "; total : " << _totalAmount << "; deposits : " << _totalNbDeposits << "; withdrawals:" << _totalNbWithdrawals << endl;
}

void Account::_displayTimestamp() {
    cout << "[19920104_091532] ";
}

void Account::displayStatus() const {
    _displayTimestamp();
    cout << "index:" << _accountIndex << "; amount : " << _amount << "; deposits : " << _nbDeposits << "; withdrawals:" << _nbWithdrawals << endl;
}

void Account::makeDeposit(int deposit) {
    _amount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    _totalAmount += deposit;
    _displayTimestamp();
    cout << "index : " << _accountIndex << "; p_amount : " << _amount - deposit << "; deposit : " << deposit << "; amount : " << _amount << "; nb_deposits:" << _nbDeposits << endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    if (withdrawal > checkAmount()) {
        cout << "index : " << _accountIndex << "; p_amount : " << _amount << "; withdrawal:refused" << endl;
        return false;
    }
    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    _totalAmount -= _amount;
    cout << "index : " << _accountIndex << "; p_amount : " << _amount - withdrawal << "; withdrawal : " << withdrawal << "; amount : " << _amount << "; nb_withdrawals:" << _nbWithdrawals << endl;
    return true;
}

int Account::checkAmount() const {
    return _amount;
}

Account::~Account() {
    _displayTimestamp();
    cout << "index : " << _accountIndex << "; amount : " << _amount << ";closed" << endl;
}





