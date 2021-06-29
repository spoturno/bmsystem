#include "../include/utils.h"
#include "../include/user.h"
#include <stdio.h>

struct _rep_user{
    ArregloChars id;
    ArregloChars name;
    nat age;
};

User createUser(nat age, ArregloChars name, ArregloChars id){
    User user = new _rep_user;
    user->age = age;
    user->id = id;
    user->name = name;
    return user;
}

void freeUser(User user)
{
    delete user;
}

ArregloChars key(User user)
{
    return user->id;
}

int age(User user)
{
    return user->age;
}

void printUser(User user)
{
    printf("\n***** New User *****\n");
    printf("Name:%s\nAge:%d\nId:%s\n", user->name, user->age, user->id);

}
