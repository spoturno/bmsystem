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
 * it will return the next element in the linked user list of the index hash.
 * Only if there were collitions this will work.
 */
User next(User user);

/*
 * chaning insertion on users chaning (collitions happens).
 */
User insertNext(User user, User newUser);

    
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
 * returns user name
 */
ArregloChars name(User user);

/*
 * returns an unique key from the user
 */
ArregloChars key(User user);


/*
 * User res returns : user->next = ref_to
 */
User refNextUser(User user, User ref_to);


/*
 * prints user information
 */
void printUserChain(User user);

#endif



