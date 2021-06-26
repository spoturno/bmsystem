
#include "../include/user.h"
#include <stdio.h>

struct _rep_user{
    int id;
    char *name;
    int age;
};

int generateId()
{
    //return id by hash function
    return 0;
}

User createUser(int age, char *name){
    User user = new _rep_user;
    user->id = generateId();
    user->age = age;
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
    printf("Name:%s\n", user->name);
    printf("Age: %d\n", user->age);
}
