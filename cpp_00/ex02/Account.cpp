#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

// Variables estáticas
int Account::total_accounts = 0;
int Account::total_balance = 0;
int Account::total_deposits = 0;
int Account::total_withdrawals = 0;

// Crea la cuenta
Account::Account(int first_deposit)
    : account_id(total_accounts), balance(first_deposit), deposit_count(0), withdrawal_count(0)  // corregido
{
    total_accounts++;
    total_balance += first_deposit;

    display_timestamp();
    std::cout << " index:" << account_id
              << ";amount:" << balance
              << ";created" << std::endl;
}

// Destruye
Account::~Account()
{
    display_timestamp();
    std::cout << " index:" << account_id
              << ";amount:" << balance
              << ";closed" << std::endl;
}

// Hacer depósito
void Account::make_deposit(int deposit)
{
    display_timestamp();
    std::cout << " index:" << account_id
              << ";prev_amount:" << balance;

    balance += deposit;
    deposit_count++;
    total_balance += deposit;
    total_deposits++;

    std::cout << ";deposit:" << deposit
              << ";amount:" << balance
              << ";nbr_deposits:" << deposit_count << std::endl;
}

// Intentar retirada
bool Account::take_money(int withdrawal)
{
    display_timestamp();
    std::cout << " index:" << account_id
              << ";prev_amount:" << balance;

    if (withdrawal > balance)
    {
        std::cout << ";withdrawal:refused" << std::endl;
        return (false);
    }

    balance -= withdrawal;
    withdrawal_count++;
    total_balance -= withdrawal;
    total_withdrawals++;

    std::cout << ";withdrawal:" << withdrawal
              << ";amount:" << balance
              << ";nbr_withdrawals:" << withdrawal_count << std::endl;

    return true;
}

// Mostrar estado de una cuenta
void Account::account_information() const
{
    display_timestamp();
    std::cout << " index:" << account_id
              << ";amount:" << balance
              << ";deposits:" << deposit_count
              << ";withdrawals:" << withdrawal_count << std::endl;
}

// Mostrar estado global del banco
void Account::status()
{
    display_timestamp();
    std::cout << " accounts:" << total_accounts
              << ";total:" << total_balance
              << ";deposits:" << total_deposits
              << ";withdrawals:" << total_withdrawals << std::endl;
}

void Account::display_timestamp()
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
