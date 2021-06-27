#ifndef _USERTABLE_H
#define _USERTABLE_H

#include "../include/user.h"
#include "../include/utils.h"

/*
 * Hash table element
 */
typedef struct _rep_user_table *UserTable;

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
UserTable createTable();

/*
 * insert an user:User into the table
 */
UserTable addUser(int key, UserTable table);


/*
 * removes the a given user from the table
 */
UserTable removeUser(User user, UserTable table); 


/*
 * deallocate the hash table user 
 */
void freeTable(UserTable table); 

#endif
