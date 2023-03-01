#pragma once
#include <string>
#include <vector>
#include "./account.h"

class User {
public:
    User(std::string id, std::string name, std::string email, std::string password, std::string address);

    std::string getId() const;
    std::string getName() const;
    std::string getEmail() const;
    std::string getPassword() const;
    std::string getAddress() const;
    std::vector<Account*> getAccounts() const;

    void setName(std::string name);
    void setEmail(std::string email);
    void setPassword(std::string password);
    void setAddress(std::string address);

    void addAccount(Account* account);
    void removeAccount(Account* account);

    int getNumAccounts() const;
    double getTotalBalance() const;


private:
    std::string m_id;
    std::string m_name;
    std::string m_email;
    std::string m_password;
    std::string m_address;
    std::vector<Account*> m_accounts;
};