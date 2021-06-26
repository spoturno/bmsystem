#include "../include/utils.h"
#include "../include/user.h"
#include <stdio.h>

struct _rep_user{
    int id;
    ArregloChars name;
    nat age;
};

int generateId()
{
    //return id by hash function
    return 0;
}

User createUser(nat age, ArregloChars name){
    User user = new _rep_user;
    user->id = generateId();
    user->age = age;
    user->name = name;
    return user;
}

void freeUser(User user)
{
    delete user;
}

int uid(User user)
{
    return user->id;
}

int age(User user)
{
    return user->age;
}

void printUser(User user)
{
    printf("***** New User *****\n");
    printf("Name:%s\n", user->name);
    printf("Age: %d\n", user->age);
}
