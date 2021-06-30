#include "../include/utils.h"
#include "../include/user.h"
#include <stdio.h>

struct _rep_user{
    ArregloChars id;
    ArregloChars name;
    nat age;
    User next;
};

User createUser(nat age, ArregloChars name, ArregloChars id){
    User user = new _rep_user;
    user->age = age;
    user->id = id;
    user->name = name;
    user->next = NULL;
    return user;
}

User next(User user)
{
    return user->next;
}

User insertNext(User user, User newUser)
{
    User temp = user;
    while(user->next != NULL)
    {
        temp = user->next;
    }
    temp->next = newUser;
    return user;
}

void freeUser(User user)
{
    if(user != NULL)
    {
        while(user->next != NULL)
        {
            User temp = user;
            user = user->next;
            delete temp;
        }
    }
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

ArregloChars name(User user)
{
    return user->name;
}

void printUser(User user)
{
    printf("\n***** New User *****\n");
    printf("Name:%s\nAge:%d\nId:%s\n", user->name, user->age, user->id);

}
