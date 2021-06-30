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

void initialScreen()
{
    printf("\e[1;1H\e[2J");
    FILE * fp;
    int c;
    fp = fopen("new.txt", "r");
    while(1)
    {
        c = fgetc(fp);
        if(feof(fp))
            break;
        printf("%c", c);
    }
    fclose(fp);
}

int getInputUser()
{
    int option;
    printf("Enter option:");
    scanf("%d", &option);
    return option;
}

User selectUser(Table table)
{
    ArregloChars id;
    printTable(table);
    printf("Inser user Id:");
    leerChars(id);
    User user = searchUser(table, id);
    if(user == NULL)
        printf("User with that Id doesn't exists");
    return (user == NULL) ? NULL : user;
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
            ArregloChars name = new char[MAX_NAME];
            ArregloChars uid = new char[MAX_UID];

            printf("Name:");
            leerChars(name);
            printf("Age:");
            age = leerNat();
            printf("Identification:");
            leerChars(uid);

            User user = createUser(age, name, uid);
            users_table = addUser(user, users_table);
            printf("%d", hashFunction(key(user)));
            printf("\nNew user added successfully.\n\n");

        } else if(option == 2){ 
            printf("hello");
            salir = true;
        } else if(option == 3){
            printf("\n");
            printTable(users_table);
        } else if(option == 4){
            User user = selectUser(users_table);
        }

    }

    //delete [] also ArregloChars
    freeTable(users_table);
    
    return 0;
}



