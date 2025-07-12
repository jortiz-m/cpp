#include "Account.hpp"

int main() 
{
    Account acc1(1000);
    acc1.make_deposit(500);
    acc1.take_money(200);
    acc1.status();

    
    Account::status();
    return (0);
}