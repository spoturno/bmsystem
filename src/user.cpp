#include "../include/utils.h"
#include "../include/user.h"
#include <stdio.h>

struct _rep_user{
    ArregloChars key;
    ArregloChars name;
    nat age;
};

User createUser(nat age, ArregloChars name, ArregloChars key){
    User user = new _rep_user;
    user->age = age;
    user->key = key;
    user->name = name;
    return user;
}

void freeUser(User user)
{
    delete user;
}

ArregloChars uid(User user)
{
    return user->key;
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
    printf("Identification: %s\n", user->key);

}
