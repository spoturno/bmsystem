/*
 * author: Tomas Spoturno
 * filename: transactions.h
 * description: This module contains the transactions representation for each User,
 * each transaction of the user will be a Transaction node of a binarySearch tree.
 * The _rep_transactions struct contains all the user transactions as a BST (tran:Transaction pointer) together with the total
 * number of transactions made and more.
 *
 *
 *
 */
#ifndef _TRANS_H_
#define _TRANS_H_

// Contains the user transactions information
typedef struct _rep_transactions *Transactions;

// Repesents the binary search tree trasaction-node. It containded in Transactions
typedef struct _rep_transaction *Transaction;

// struct that contains the information of each transaction-node
typedef struct _rep_infotrac *Infotrac;

/*
 * shows all the current transactions made by all the users
 */
void showTransactions();

/*
 * returns a transaction block with 0 transaction and a NULL trasaction
 */
Transactions createEmptyTransactions();

/*
 * creates a new transaction to add
 */
Transaction createTransation();

/*
 * Adds a new node (to_add) to the binary search tree tran:Transaction 
 */
Transaction addTransaction(Transaction to_add, Transaction tran);

/*
 * This function calls addTransaction giving the following arguments: to_add and t->tran.
 * Also the total of transaction increase 1.
 *
 */
Transactions addToTransactions(Transaction to_add, Transactions t);


/*
 * removes the to_remove transaction from the user Transactions t
 */
Transactions removeTransaction(Transaction to_remove, Transactions t);


#endif
