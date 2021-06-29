#include "include/user.h"
#include "include/utils.h"
#include "include/userTable.h"

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_NAME 32
#define MAX_UID 10

typedef struct _rep_node *Node;

struct _rep_node
{
    int dato;        
    Node next;
};


void initialScreen()
{
    printf("\e[1;1H\e[2J");
    printf("\n|******************************************|");
    printf("\n|          Bank Managment System           |");
    printf("\n|******************************************|");
    printf("\n|                                          |");
    printf("\n|    [1] Insert new user                   |");
    printf("\n|    [2] Manage Transaction                |");
    printf("\n|    [3] User book                         |");
    printf("\n|    [4] Transaction book                  |");
    printf("\n|    [0] Exit                              |");
    printf("\n|                                          |");
    printf("\n|******************************************|");
    printf("\n\n");
}

int getInputUser()
{
    int option;
    printf("Enter option:");
    scanf("%d", &option);
    return option;
}

int main ()
{
    Table users_table = createTable();

    bool salir = false;
    initialScreen();

    while (!salir)
    {
        int option = getInputUser();

        if(option == 0){
            salir = true;
            printf("See you later!\n");
        } else if (option == 1){
            nat age;
            char name[MAX_NAME];
            char uid[MAX_UID];

            printf("Name:");
            leerChars(name);
            printf("Age:");
            age = leerNat();
            printf("Identification:");
            leerChars(uid);

            User user = createUser(age, name, uid);
            users_table = addUser(user, users_table);
            printf("key:%d", hashFunction(key(user)));
            printUser(user);
            printf("\nNew user added \n");

        } else if(option == 2){ 
            printf("hello");
            salir = true;
        } else if(option == 3){
            printf("\n");
            printTable(users_table);
        }



    }

    freeTable(users_table);
    
    return 0;
}



