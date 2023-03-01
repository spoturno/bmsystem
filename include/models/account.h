#pragma once

class Account {
public:
    Account(int number, double balance, User* owner);
    
    int getNumber() const;
    double getBalance() const;
    User* getOwner() const;

    void setBalance(double balance);
    void setOwner(User* owner);
private:
    int m_number;
    double m_balance;
    User* m_owner;
};