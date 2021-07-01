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
nat hashFunction(char* key){
    nat hashVal = 0;
    for(nat i=0; i<sizeof(key); i++)
       hashVal= 37 * hashVal + key[i];
    return hashVal % MAX_USERS;
}

Table createTable(){
    Table table = new _rep_table; 
    table->array = new User[MAX_USERS];
    table->count = 0;
    for (int i=0; i<MAX_USERS; i++)
        table->array[i] = NULL;
    return table;
}

Table addUser(User user, Table table){
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
            table->count++;
        }
    }
    return table;
}

Table handleCollision(User user, Table table, nat index){
    //search the last user node
    table->array[index] = insertNext(table->array[index], user);
    return table;
}

Table removeUser(User user, Table table){
    nat index = hashFunction(key(user));
    User temp = table->array[index];
    if(temp == NULL)
        return table;
    else{
        if(next(temp) == NULL && strcmp(key(temp), key(user)) == 0){
            //no collision chain. Just remove temp.
            table->array[index] = NULL;
            freeUser(temp);
            table->count--;
            return table;
        }else if(next(temp) != NULL)
            // collision exists
            if(strcmp(key(temp), key(user)) == 0){
                table->array[index] = next(temp);
                freeUser(temp);
                table->count--;
                return table;
            }
            User current = next(temp);
            User previous = NULL; 
            while(current){
                if(strcmp(key(user), key(current)) == 0){
                    table->count--;
                    if(previous == NULL){
                        table->array[index] = refNextUser(table->array[index], next(current));
                        freeUser(current);
                        return table;
                    }else{
                        previous = refNextUser(previous, next(current));
                        freeUser(current);
                        return table;
                    }
                }
                previous = current;
                current = next(current);
            }
    }
    return table;
}

bool contains(Table table, User user){
    int hashed_key = hashFunction(key(user));
    User temp = table->array[hashed_key];
    while(next(temp) != NULL){
        if(temp == user)
            return true;
        temp = next(temp);
    }
    return (temp == user) ? true : false;
}

User searchUser(Table table, ArregloChars id){
    nat index = hashFunction(id);
    User temp = table->array[index];
    while(next(temp) != NULL){
        if(strcmp(key(temp), id) == 0)
            return temp;
        temp = next(temp);
    }
    return (strcmp(key(temp), id) == 0) ? temp : NULL;
}

nat numberOfUsers(Table table){
    return table->count;
}

bool isEmptyBucket(Table table, int index){
    return (table->array[index] == NULL) ? true : false;
}

bool isEmptyTable(Table table){
    bool temp = false;
    int i;
    for(i=0; i<MAX_USERS; i++){
        if(table->array[i] != NULL){
            temp = false;
            break;
        }
    }
    if(i == MAX_USERS)
        temp = true;
    return temp;
}

void freeTable(Table table){
    for(int i=0; i<MAX_USERS; i++)
        freeUser(table->array[i]);
    delete table;
}

void printTable(Table table){
    printf("\n");
    printf("+-----------------+-----------------+------+-----------+\n");
    printf("| Id              | Name            | Age  | Balance   |\n");
    printf("+-----------------+-----------------+------+-----------+\n");
    for(int i=0; i<MAX_USERS; i++){
        if(table->array[i] != NULL){
            printf("| %-15s | %-15s | %-4d | $%-8d |\r\n", key(table->array[i]), name(table->array[i]), age(table->array[i]), balance(table->array[i])); ;
            printUserChain(table->array[i]);
        }
    }
    printf("+-----------------+-----------------+------+-----------+\n");
}

/*
 * (a - '0') ~ ((int)a) - ((int)'0') = 4
 * */

    
