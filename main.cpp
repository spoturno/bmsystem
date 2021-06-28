#include "include/user.h"
#include "include/utils.h"
#include "include/userTable.h"

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_NAME 32

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


//shows all the current users
void printUserBook(){
}

int main ()
{

    bool salir = false;
    initialScreen();

    while (!salir)
    {
        int option = getInputUser();

        if(option == 0){
            salir = true;
            printf("Hasta pronto!\n");
        } else if (option == 1){
            nat age;
            char name[MAX_NAME];

            printf("Name:");
            leerChars(name);
            printf("Age:");
            age = leerNat();
            printf("\n");

            char persona[7] = "person";
            int key = hashFunction(persona);
            printf("%d\n", key);


            User user = createUser(age, name);
            printUser(user);
            printf("\nNew user added \n");
            salir = false;
            
        } else if(option == 2){ 
            printf("hello");
            salir = true;
        }
    }
    
    return 0;
}







