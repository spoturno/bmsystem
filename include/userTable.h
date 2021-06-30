#ifndef _USERTABLE_H
#define _USERTABLE_H

#include "../include/user.h"
#include "../include/utils.h"

/*
 * Hash table
 */
typedef struct _rep_table *Table;

/*
 * hash function  
 */
nat hashFunction(char *key);


/*
 * creates an empty table - Hash table -
 */
Table createTable();

/*
 * insert an user:User into the table
 */
Table addUser(User user, Table table);

/*
 * handles collision using linear probing
 */
Table handleCollision(User user, Table table, nat index);

/*
 * removes the a given user from the table
 */
Table removeUser(User user, Table table); 

/*
 * returns true if user:User is in the table:Table
 * NULL is not defined as a user.
*/
bool contains(Table table, User user);

/*
 * search and returns the user with id.
 */
User searchUser(Table table, ArregloChars id);

/*
 * returns ture if table->array[index] == NULL
 */
bool isEmptyBuckey(Table table, int index);

/*
 * returns true if there's no user in the table, 
 * NULL is not defined as a user.
 */
bool isEmptyTable(Table table);

/*
 * returns the cuatity of the users in the table
 */
nat numberOfUsers(Table table);

/*
 * deallocate the hash table user 
 */
void freeTable(Table table); 

/*
 * print all the users inside the table 
 */
void printTable(Table table);


#endif
