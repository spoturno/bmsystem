#ifndef _USER_H
#define _USER_H

#include "./utils.h"
#include <time.h>
#include "transactions.h"
typedef struct _rep_user *User; 
//define operations for user


/*
 * creates a new user with a given first_name, age, ...
 */
User createUser(ArregloChars first_name, ArregloChars last_name, nat age, ArregloChars account, int balance);

/*
 * it will return the next element in the linked user list of the index hash.
 * Only if there were collitions this will work.
 */
User next(User user);

/*
 * chaning insertion on users chaning (collitions happens).
 */
User insertNext(User user, User newUser);


/*
 * modify the user:User selected data from the input.  
 */
User modifyUser(User user);

    
/*
 * free user memory
 */
void freeUser(User user);


/*
 * returns user id
 */
ArregloChars uid(User user);

/*
 * returns user balance
 */
int balance(User user);

/*
 * adds a_balance to the current user balance. Could be a negative balance.
 */
User addBalance(User user ,int a_balance);

/*
 * return user age
 */
int age(User user);

/*
 * returns user first_name
 */
ArregloChars first_name(User user);

/*
 * returns user last_name
 */
ArregloChars last_name(User user);

/*
 * returns an unique key from the user
 */
ArregloChars account(User user);

/*
 * returns the time when user got logged in
 */
struct tm * userAdmissionDate(User user);


/*
 * User res returns : user->next = ref_to
 */
User refNextUser(User user, User ref_to);


/*
 * prints user information
 */
void printUserChain(User user);


/*
 * returns the first time user was insert on the table
 */
time_t user_since(User user);

/*
 * returns the user trc:Transactions 
 */
Transactions transactions(User user);

/*
 * assings t:Transactions to user->trc:Transactions
 */
User assignTransactions(User user,Transactions t);


/*
 * returs a random bank account number which sould be a string of 8 chars (nums)
 */
ArregloChars generateAccount();

#endif



