#ifndef _USER_H
#define _USER_H

#include "./utils.h"

typedef struct _rep_user *User;

//define operations for user

/*
 * returns unique id implemented with hash function 
 */
int generateId();


/*
 * creates a new user with a given name, age, ...
 */
User createUser(int age, ArregloChars name);

    
/*
 * free user memory
 */
void freeUser(User user);


/*
 * returns user id
 */
int uid(User user);

/*
 * return user age
 */
int age(User user);

/*
 * prints user information
 */
void printUser(User user);

#endif



