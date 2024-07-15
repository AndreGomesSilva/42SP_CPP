
#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <ostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0),
      _nbWithdrawals(0) {
  _nbAccounts++;
  _totalAmount += initial_deposit;
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created"
            << std::endl;
}

Account::~Account(void) {
  _displayTimestamp();
  std::cout << "index" << _accountIndex << ";amount" << _amount << ";closed"
            << std::endl;
  _nbAccounts--;
  _totalAmount -= _amount;
}

int Account::getNbAccounts(void) { return _nbAccounts; }

int Account::getTotalAmount(void) { return _totalAmount; }

int Account::getNbDeposits(void) { return _totalNbDeposits; }

int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

void Account::displayAccountsInfos(void) {
  _displayTimestamp();
  std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
            << ";deposits:" << _totalNbDeposits << ";withdrawals:"
            << _totalNbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
  _displayTimestamp();
  if (deposit <= 0) {
    std::cout << "Deposit have to be greate than 0";
    return;
  }
  _amount += deposit;
  _nbDeposits++;
  _totalAmount += deposit;
  _totalNbDeposits++;
  std::cout << "index:" << _accountIndex << ";p_amount:" << (_amount - deposit)
            << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits
            << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
  _displayTimestamp();
  if (_amount >= withdrawal) {
    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << (_amount + withdrawal)
              << ";withdrawal:" << _nbWithdrawals << ";amount:" << _amount
              << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
  } else {
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
              << ";withdrawal::refused" << std::endl;
    return false;
  }
}

int Account::checkAmount(void) const { return _amount; }

void Account::displayStatus(void) const {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount
            << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals
            << std::endl;
}

void Account::_displayTimestamp(void) {
  std::time_t now = std::time(NULL);
  tm *ltm = std::localtime(&now);
  std::cout << "[" << 1900 + ltm->tm_year << (ltm->tm_mon < 9 ? "0" : "")
            << 1 + ltm->tm_mon << (ltm->tm_mday < 10 ? "0" : "") << ltm->tm_mday
            << "_" << (ltm->tm_hour < 10 ? "0" : "") << ltm->tm_hour
            << (ltm->tm_min < 10 ? "0" : "") << ltm->tm_min
            << (ltm->tm_sec < 10 ? "0" : "") << ltm->tm_sec << "]";
}
