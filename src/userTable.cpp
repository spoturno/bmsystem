#include "../include/userTable.h"
#include "../include/utils.h"
#include "../include/user.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 13

struct _rep_table{
    User *array;
    nat count;
};

//the key is the user identification
nat hashFunction(char* key)
{
    nat hashVal = 0;
    for(nat i=0; i<sizeof(key); i++)
       hashVal= 37 * hashVal + key[i];
    return hashVal % MAX_USERS;
}

Table createTable()
{
    Table table = new _rep_table; 
    table->array = new User[MAX_USERS];
    table->count = 0;
    for (int i=0; i<MAX_USERS; i++)
        table->array[i] = NULL;
    return table;
}

Table addUser(User user, Table table)
{
    nat index = hashFunction(key(user)); 
    User current_user = table->array[index];
    if(current_user == NULL){
        if(table->count == MAX_USERS){
            printf("Error: User Table is Full\n");
            freeUser(user);
            return table;
        }
       //insert directly
       table->array[index] = user;
       table->count++;
    } else{
        //case 1 - update the value
        if(strcmp(key(current_user), key(user)) == 0){
            table->array[index] = user;
        } else{//case 2 - insert in chained users
            table = handleCollision(user, table, index);
        }
    }
    return table;
}

Table handleCollision(User user, Table table, nat index)
{
    //search the last user node
    table->array[index] = insertNext(table->array[index], user);
    return table;
}

Table removeUser(User user, Table table)
{
    return NULL;
}

bool contains(Table table, User user)
{
    int hashed_key = hashFunction(key(user));
    return (table->array[hashed_key] == NULL) ? true : false;
}

nat numberOfUsers(Table table)
{
    return table->count;
}

bool isEmptyBucket(Table table, int index)
{
    return (table->array[index] == NULL) ? true : false;
}

bool isEmptyTable(Table table)
{
    bool temp = false;
    int i;
    for(i=0; i<MAX_USERS; i++)
    {
        if(table->array[i] != NULL)
        {
            temp = false;
            break;
        }
    }
    if(i == MAX_USERS)
        temp = true;
    return temp;
}

void freeTable(Table table)
{
    for(int i=0; i<MAX_USERS; i++)
        freeUser(table->array[i]);
    delete table;
}

void printTable(Table table)
{
    printf("\n");
    printf("+-----------------+-----------------+------+\n");
    printf("| Id              |     Name        | Age  |\n");
    printf("+-----------------+-----------------+------+\n");
    for(int i=0; i<MAX_USERS; i++)
    {
        if(table->array[i] != NULL)
        {
            printf("| %-15s | %-15s | %-4d |\r\n", key(table->array[i]), name(table->array[i]), age(table->array[i])); ;
            printUserChain(table->array[i]);
        }
    }
    printf("+-----------------+-----------------+------+\n");
}

/*
 * (a - '0') ~ ((int)a) - ((int)'0') = 4
 * */

    
