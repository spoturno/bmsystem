#include <stdio.h>
#include <time.h>

#include "../include/transactions.h"
#include "../include/user.h"

struct _rep_transactions{
    Transaction tran;
    nat total_transactions;
};

struct _rep_transation{
    Transaction left;
    Transaction right;
    Infotrac info;
};


struct _rep_infotrac{
    User receiver;
    nat amount;
    struct tm * date;
};


Transaction createTransation(){
    return NULL;
}

Transactions addTransaction(Transactions t){
    return NULL;
}

Transactions removeTransaction(Transaction to_remove, Transactions t){
        return NULL;
}


void showTransactions(){
}
