#include "../include/userTable.h"
#include "../include/utils.h"
#include "../include/user.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 13

struct _rep_table{
    User *array;
};

int hashFunction(char *key)
{
    int hashVal = 0;
    for(int i=0; i<sizeof(key); i++)
    {
        hashVal= 37 * hashVal + key[i];
    }
    return hashVal % MAX_USERS;
}

Table createTable()
{
    Table table = new _rep_table; 
    table->array = new User[MAX_USERS];
    return table;
}

Table addUser(User user, Table table)
{
    return NULL;
}

Table removeUser(User user, Table table)
{
    return NULL;
}

bool contains(Table table, User user)
{
    int hashed_key = hashFunction(uid(user));
    return (table->array[hashed_key] == NULL) ? true : false;
}

/*
 * (a - '0') ~ ((int)a) - ((int)'0') = 4
 * */

    
