#ifndef __DBASE__
#define __DBASE__

#include <sqlite3.h>
#include "../include/user.h"
#include "../include/utils.h"

//this module will be added to src directory


/*
 * create the database binary file
 */
sqlite3 createDatabase();

/*
 * add a user data to the database
 */
sqlite3 addUserToDatabase(User user);

/*
 * returns the user with acc (account number) 
 */
User getUserDatabase(ArregloChars acc);

/*
 * modify an existing user in database with the  
 */
sqlite3 modifyUserDatabase(ArregloChars acc);

/*
 * removes the user with the acc number
 */
sqlite3 removeUserDatabase(ArregloChars acc);

/*
 * print the Users table
 */
void showUsersDatabase(ArregloChars acc);


#endif
