#ifndef _USERTABLE_H
#define _USERTABLE_H

#include "../include/user.h"
#include "../include/utils.h"

/*
 * Hash table
 */
typedef struct _rep_table *Table;

/*
 * 
 */
int hashCode(int key);


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
 * deallocate the hash table user 
 */
void freeTable(Table table); 

#endif
