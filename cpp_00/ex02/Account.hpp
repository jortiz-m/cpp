#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

class Account
{
public:
    Account(int first_deposit);
    ~Account();

    void make_deposit(int deposit);
    bool take_money(int withdrawal);
    void account_information() const;

    static void status();

private:
    static int total_accounts;
    static int total_balance;
    static int total_deposits;
    static int total_withdrawals;

    int account_id;       
    int balance;           
    int deposit_count;     
    int withdrawal_count;  

    static void display_timestamp();
};

#endif