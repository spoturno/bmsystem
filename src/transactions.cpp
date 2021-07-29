#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

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

bool isEmptyTransaction(Transaction t){
    return (t == NULL ? true : false);
}

bool isValidTransaction(Transaction t){
    //TODO
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

Transactions addToTransaction(Transaction to_add, Transactions t){
    assert(isValidTransaction(to_add));
    t->total_transactions++;
    t->tran = addTransaction(to_add, t->tran);
    return t;
}

Transaction addTransaction(Transaction to_add, Transaction tran){
    //TODO
    return NULL;
}

Transaction searchTransaction(Transaction to_search, Transaction tran){
    if(tran == NULL || tran->info->amount == to_search->info->amount)    
       return tran; 
    if(to_search->info->amount > tran->info->amount)
        return addTransaction(to_search, tran->right); 
    return addTransaction(to_search, tran->left);
}

Transactions removeOfTransactions(Transaction to_remove, Transactions t){
    assert(isValidTransaction(to_remove));
    t->total_transactions--;
    t->tran = removeTransaction(to_remove, t->tran);
    return t;
}

Transaction removeTransaction(Transaction to_remove, Transaction tran){
    //TODO
    return NULL;
}

Transaction minTransaction(Transaction tran){
    if(tran->left == NULL)
        return tran;
    return tran->left;
}

void showTransactions(){
    //TODO
}

