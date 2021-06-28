#ifndef _USER_H
#define _USER_H

#include "./utils.h"

typedef struct _rep_user *User;

//define operations for user


/*
 * creates a new user with a given name, age, ...
 */
User createUser(nat age, ArregloChars name, ArregloChars key);

    
/*
 * free user memory
 */
void freeUser(User user);


/*
 * returns user id
 */
ArregloChars uid(User user);

/*
 * return user age
 */
int age(User user);

/*
 * prints user information
 */
void printUser(User user);

#endif



