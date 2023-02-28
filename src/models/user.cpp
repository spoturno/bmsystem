#include "../../include/models/user.h"

User::User(std::string name, std::string email, std::string password) : m_name(name), m_email(email), m_password(password) {}

std::string User::getEmail() const {
    return m_email;
}

std::string User::getName() const {
    return m_name;
}

void User::setEmail(std::string email) {
    m_email = email;
}

bool User::verifyPassword(std::string password) const {
    return m_password == password;
}
