#include "./account.h"

class Transaction {
public:
    Transaction(Account* source, Account* destination, double amount);
    Account* getSource() const;
    Account* getDestination() const;
    double getAmount() const;
private:
    Account* m_source;
    Account* m_destination;
    double m_amount;
};
