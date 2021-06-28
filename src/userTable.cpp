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
    for (int i=0; i<MAX_USERS; i++)
        table->array[i] = NULL;
    return table;
}

Table addUser(User user, Table table)
{
    int index = hashFunction(uid(user)); 
    while(index <= MAX_USERS)
    {
        if(table->array[index] != NULL)    
            index++;
        else if(index == MAX_USERS)
            printf("Error, not enough space available");
        else 
        {
            table->array[index] = user;
            break;
        }
    }
    return table;
}

Table removeUser(User user, Table table)
{
    int index = hashFunction(uid(user));
    if(contains(table, user)){
        freeUser(table->array[index]);
        table->array[index] = NULL;
    } else{
        //shearch trough the array
    }
    return table;
}

bool contains(Table table, User user)
{
    int hashed_key = hashFunction(uid(user));
    return (table->array[hashed_key] == NULL) ? true : false;
}


bool isEmptyBucket(Table table, int index)
{
    return (table->array[index] == NULL) ? true : false;
}

bool isEmptyTable(Table table)
{
    bool temp = false;
    int i = 0;
    while(i < MAX_USERS)
    {
        if(table->array[i] != NULL)
        {
            temp = false;
            break;
        }
        i++;
    }
    if(i == MAX_USERS)
        temp = true;
    return temp;
}

/*
 * (a - '0') ~ ((int)a) - ((int)'0') = 4
 * */

    
