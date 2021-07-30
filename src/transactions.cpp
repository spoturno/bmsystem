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

//change amount to floating (TODO)
struct _rep_infotrac{
    User receiver;
    nat amount;
    struct tm * date;
};

bool isEmptyTransaction(Transaction t){
    return (t == NULL ? true : false);
}

bool isValidTransaction(Transaction tran){
    return (tran->info->amount <= 0 ? false : true);
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
    if(tran == NULL)
        return createTransation(to_add->info->amount, to_add->info->receiver);
    
    if(to_add->info->amount < tran->info->amount)
        tran->left = addTransaction(to_add, tran->left);
    else tran->right = addTransaction(to_add, tran->right);

    return tran;
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
    if(tran == NULL)
        return tran;

    if(to_remove->info->amount < tran->info->amount)
        tran->left = removeTransaction(to_remove, tran->left);
    else if(to_remove->info->amount > tran->right->info->amount)
        tran->right = removeTransaction(to_remove, tran->right);
    else{//same key         
        //node has no child
        if(tran->right == NULL && tran->left == NULL)
            return NULL;
        //node with only one child
        else if(tran->left == NULL){
            Transaction temp = tran->right;
            delete tran;
            return temp;
        }
        else if(tran->right == NULL){
            Transaction temp = tran->left;
            delete tran;
            return temp;
        }
        // node with two children: get the inorder successor
        // (samallest in the right subtree)
        Transaction temp = minTransaction(tran->right);
        tran->info = temp->info;
        tran->right = removeTransaction(tran->right, temp->right);
    }
    return tran;
}

Transaction minTransaction(Transaction tran){
    assert(isValidTransaction(tran));
    Transaction current = tran;
    while(current && current->left)
        current = current->left;
    return current;
}

void showTransactions(Transactions t){
    assert(!isEmptyTransaction(t->tran));
    printf("Transactions of User | Total: %d", t->total_transactions);
    printf("--------------------------------------");
    formattedTransaction(t->tran);
}

void formattedTransaction(Transaction tran, nat count){
    if(tran != NULL){
        formattedTransaction(tran->left);
        printf("%d - Amount: %d - Reciever: %s", count, tran->info->amount, name(tran->info->receiver));
        formattedTransaction(tran->right);
    }
}

