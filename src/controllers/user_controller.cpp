#include "UserController.h"

void UserController::addUser(int id, std::string name, std::string email, std::string password) {
    User* user = new User(id, name, email, password);
    m_bank.addUser(user);
}

void UserController::removeUser(int id) {
    User* user = getUserById(id);
    if (user != nullptr) {
        m_bank.removeUser(user);
        delete user;
    }
}

std::vector<User*> UserController::getAllUsers() const {
    return m_bank.getUsers();
}

User* UserController::getUserById(int id) const {
    std::vector<User*> users = m_bank.getUsers();
    for (User* user : users) {
        if (user->getId() == id) {
            return user;
        }
    }
    return nullptr;
}

void UserController::addAccountToUser(int userId, int accountNumber, double balance) {
    User* user = getUserById(userId);
    if (user != nullptr) {
        Account* account = new Account(accountNumber, balance, user);
        user->addAccount(account);
        m_bank.addAccount(account);
    }
}

void UserController::removeAccountFromUser(int userId, int accountNumber) {
    User* user = getUserById(userId);
    if (user != nullptr) {
        std::vector<Account*> accounts = user->getAccounts();
        for (Account* account : accounts) {
            if (account->getNumber() == accountNumber) {
                user->removeAccount(account);
                m_bank.removeAccount(account);
                delete account;
                return;
            }
        }
    }
}

std::vector<Account*> UserController::getAccountsForUser(int userId) const {
    User* user = getUserById(userId);
    if (user != nullptr) {
        return user->getAccounts();
    }
    return std::vector<Account*>();
}