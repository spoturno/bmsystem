#include "../../include/models/account.h"
#include "../../include/models/user.h"

// Constructor implementation
User::User(std::string name, std::string address, std::string email, std::string password, std::string address) : 
    m_name(name), 
    m_email(email), 
    m_password(password),
    m_address(address), 
{}

std::string User::getName() const {
    return m_name;
}

void User::setName(std::string name) {
    m_name = name;
}

std::string User::getAddress() const {
    return m_address;
}

void User::setAddress(std::string address) {
    m_address = address;
}

std::string User::getEmail() const {
    return m_email;
}

void User::setEmail(std::string email) {
    m_email = email;
}

std::string User::getPassword() const {
    return m_password;
}

void User::setPassword (std::string password) {
    m_password = password;
}

void User::addAccount(Account* account) {
    m_accounts.push_back(account);
}

void User::removeAccount(Account* account){
    // Use an iterator to search for the account in the vector
    auto it = std::find(m_accounts.begin(), m_accounts.end(), account);

    // If the account is found, remove it from the vector
    if (it != m_accounts.end()) m_accounts.erase(it);
}

int User::getNumAccounts() const{
    return m_accounts.size();
}

double User::getTotalBalance() const {
    double total = 0.0;

    for (const auto& account : m_accounts) {
        total += account->getBalance();
    }

    return total;
}
