#pragma once
#include <vector>
#include "User.h"

class UserController {
public:
    void addUser(int id, std::string name, std::string email, std::string password);
    void removeUser(int id);
    std::vector<User*> getAllUsers() const;
    User* getUserById(int id) const;
    void addAccountToUser(int userId, int accountNumber, double balance);
    void removeAccountFromUser(int userId, int accountNumber);
    std::vector<Account*> getAccountsForUser(int userId) const;
private:
    Bank m_bank;
};