#include "./user.h"
#include "./account.h"

class Bank {
public:
    std::vector<User*> getUsers() const;
    std::vector<Account*> getAccounts() const;

    void addUser(User* user);
    void removeUser(User* user);

    void addAccount(Account* account);
    void removeAccount(Account* account);
private:
    std::vector<User*> m_users;
    std::vector<Account*> m_accounts;
};