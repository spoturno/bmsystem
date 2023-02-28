#ifndef USER_H
#define USER_H

#include <string>

std::string;

class User {
public:
    User(std::string name, std::string email, std::string password);

    std::string getName() const;
    std::string getEmail() const;

    void setEmail(std::string email);
    bool verifyPassword(std::string password) const;
private:
    std::string m_name;
    std::string m_email;
    std::string m_password;
};

#endif /* USER_H */