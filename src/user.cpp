#include "../include/utils.h"
#include "../include/user.h"
#include <stdio.h>

struct _rep_user{
    ArregloChars id;
    ArregloChars name;
    nat age;
    int key;
};

User createUser(nat age, ArregloChars name, ArregloChars id, int key){
    User user = new _rep_user;
    user->age = age;
    user->id = id;
    user->name = name;
    user->key = key;
    return user;
}

void freeUser(User user)
{
    delete user;
}

ArregloChars uid(User user)
{
    return user->id;
}

int key(User user)
{
    return user->key;
}

int age(User user)
{
    return user->age;
}

void printUser(User user)
{
    printf("\n***** New User *****\n");
    printf("Name:%s\n Age:%d\n, Id:%s\n", user->name, user->age, user->id);

}
