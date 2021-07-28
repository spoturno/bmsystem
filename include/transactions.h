/*
 * author: Tomas Spoturno
 * filename: transactions.h
 * description: This module contains the transactions representation for each User,
 * each transaction of the user will be a Transaction node node of a binarySearch tree.
 * The Transaction struct contains all the user transactions (BST) together with the total
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
typedef struct _rep_trasaction *Transaction;

// struct that contains the information of each transaction-node
typedef struct _rep_infotrac *Infotrac;

/*
 * shows all the current transactions made by all the users
 */
void showTransactions();

/*
 * creates a new transaction to add
 */
Transaction createTransation();

/*
 * adds the to_add transaction to the user Transactions t
 */
Transactions addTransaction(Transaction to_add, Transactions t);


/*
 * removes the to_remove transaction from the user Transactions t
 */
Transactions removeTransaction(Transaction to_remove, Transactions t);


#endif
