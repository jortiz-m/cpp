#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

class Account
{
public:
    Account(int first_deposit);   // Constructor
    ~Account();                     // Destructor

    void make_deposit(int deposit);  // Añadir dinero
    bool take_money(int withdrawal); // Sacar dinero
    void account_information() const;     // Mostrar info de una cuenta

    static void status(); // Mostrar info global

private:
    static int total_accounts;
    static int total_balance;
    static int total_deposits;
    static int total_withdrawals;

    int account_id;       
    int balance;           
    int deposit_count;     
    int withdrawal_count;  

    static void _displayTimestamp();
};

#endif