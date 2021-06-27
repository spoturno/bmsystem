#ifndef _USERTABLE_H
#define _USERTABLE_H

#include "../include/user.h"
#include "../include/utils.h"

/*
 * Hash table
 */
typedef struct _rep_table *Table;

/*
 * hash function using the Hornes's rule  
 */
int hashFunction(char *key);


/*
 * creates an empty table - Hash table -
 */
Table createTable();

/*
 * insert an user:User into the table
 */
Table addUser(int key, Table table);


/*
 * removes the a given user from the table
 */
Table removeUser(User user, Table table); 


/*
 * returns true if user:User is in the table, else if
 * user == NULL return false. using the hash function 
 * */
bool contains(Table table, User user);


/*
 * deallocate the hash table user 
 */
void freeTable(Table table); 

#endif
