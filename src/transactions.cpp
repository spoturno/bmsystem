#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../include/transactions.h"
#include "../include/user.h"
#include "../include/timer.h"

struct _rep_transactions{
    Transaction tran;
    nat total_transactions;
};

struct _rep_transaction{
    Transaction left;
    Transaction right;
    Infotrac info;
};


struct _rep_infotrac{
    User receiver;
    nat amount;
    struct tm * date;
};

bool isValidTransaction(Transaction t){
    return false;
}

Transactions createEmptyTransactions(){
   Transactions trans = new _rep_transactions; 
   trans->total_transactions = 0;
   trans->tran = NULL;
   return trans;
}

Transaction createTransation(nat amount, User receiver){
    Transaction t = new _rep_transaction;
    Infotrac info = new _rep_infotrac;
    info->amount = amount;
    info->receiver = receiver;
    info->date = getCurrentTime();
    t->info = info;
    t->left = t->right = NULL;
    return t;
}

Transactions addTransaction(Transaction to_add, Transactions t){
    t->total_transactions++;
    t->tran = addTran(to_add, t->tran);
    return NULL
}

Transactions removeTransaction(Transaction to_remove, Transactions t){
        return NULL;
}


void showTransactions(){
}
