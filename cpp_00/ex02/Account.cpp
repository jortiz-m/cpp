#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

// Inicialización de variables estáticas
int Account::total_accounts = 0;
int Account::total_balance = 0;
int Account::total_deposits = 0;
int Account::total_withdrawals = 0;  // corregido

// Constructor
Account::Account(int first_deposit)
    : account_id(total_accounts), balance(first_deposit), deposit_count(0), withdrawal_count(0)  // corregido
{
    total_accounts++;
    total_balance += first_deposit;

    _displayTimestamp();
    std::cout << " index:" << account_id
              << ";amount:" << balance
              << ";created" << std::endl;
}

// Destructor
Account::~Account()
{
    _displayTimestamp();
    std::cout << " index:" << account_id
              << ";amount:" << balance
              << ";closed" << std::endl;
}

// Hacer depósito
void Account::make_deposit(int deposit)
{
    _displayTimestamp();
    std::cout << " index:" << account_id
              << ";p_amount:" << balance;

    balance += deposit;
    deposit_count++;
    total_balance += deposit;
    total_deposits++;

    std::cout << ";deposit:" << deposit
              << ";amount:" << balance
              << ";nb_deposits:" << deposit_count << std::endl;
}

// Intentar retirada
bool Account::take_money(int withdrawal)
{
    _displayTimestamp();
    std::cout << " index:" << account_id
              << ";p_amount:" << balance;

    if (withdrawal > balance)
    {
        std::cout << ";withdrawal:refused" << std::endl;
        return false;
    }

    balance -= withdrawal;
    withdrawal_count++;
    total_balance -= withdrawal;
    total_withdrawals++;

    std::cout << ";withdrawal:" << withdrawal
              << ";amount:" << balance
              << ";nb_withdrawals:" << withdrawal_count << std::endl;

    return true;
}

// Mostrar estado de una cuenta
void Account::account_information() const
{
    _displayTimestamp();
    std::cout << " index:" << account_id
              << ";amount:" << balance
              << ";deposits:" << deposit_count
              << ";withdrawals:" << withdrawal_count << std::endl;
}

// Mostrar estado global del banco
void Account::status()
{
    _displayTimestamp();
    std::cout << " accounts:" << total_accounts
              << ";total:" << total_balance
              << ";deposits:" << total_deposits
              << ";withdrawals:" << total_withdrawals << std::endl;
}

// Mostrar timestamp formateado
void Account::_displayTimestamp()
{
    std::time_t now = std::time(0);
    std::tm *ltm = std::localtime(&now);

    std::cout << "["
              << 1900 + ltm->tm_year
              << std::setw(2) << std::setfill('0') << ltm->tm_mon + 1
              << std::setw(2) << std::setfill('0') << ltm->tm_mday << "_"
              << std::setw(2) << std::setfill('0') << ltm->tm_hour
              << std::setw(2) << std::setfill('0') << ltm->tm_min
              << std::setw(2) << std::setfill('0') << ltm->tm_sec
              << "]";
}
