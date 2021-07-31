#include "include/user.h"
#include "include/utils.h"
#include "include/userTable.h"
#include "include/transactions.h"

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_NAME 32
#define MAX_UID 10

void initialScreen(){
    printf("\e[1;1H\e[2J");
    FILE * fp;
    int c;
    fp = fopen("screen.txt", "r");
    while(1){
        c = fgetc(fp);
        if(feof(fp))
            break;
        printf("%c", c);
    }
    fclose(fp);
}

int getInputUser(){
    int option;
    printf("Enter option:");
    scanf("%d", &option);
    return option;
}

User selectUser(Table table){
    ArregloChars id = new char[MAX_UID];
    printTable(table);
    printf("Inser user Id:");
    leerChars(id);
    User user = searchUser(table, id);
    if(user == NULL)
        printf("User with that Id doesn't exists\n");
    return (user == NULL) ? NULL : user;
}

int main (){
    Table users_table = createTable();
    bool salir = false;
    initialScreen();

    while (!salir){
        int option = getInputUser();

        //exit
        if(option == 0){
            salir = true;
            printf("See you later!\n");

        //add user
        } else if (option == 1){
            nat age; int balance; char temp;
            ArregloChars name = new char[MAX_NAME];
            ArregloChars uid = new char[MAX_UID]; 

            printf("Full Name:");
            scanf("%c", &temp);
            scanf("%[^\n]", name);
            printf("Age:");
            age = leerNat();
            printf("Identification:");
            leerChars(uid);
            printf("Account balance:");
            scanf("%d", &balance);
            printf("\n");

            User user = createUser(age, name, uid, balance);
            users_table = addUser(user, users_table);
            printf("\n-New user added successfully-\n\n");

        //modify user data
        } else if(option == 2){ 
            User user = selectUser(users_table);
            user = modifyUser(user);
            printf("User modified correctly\n\n");
    
        //show user book
        } else if(option == 3){
            printf("\n");
            printTable(users_table);

            
        //remove user account
        } else if(option == 4){
            User user = selectUser(users_table);
            if(user != NULL){
                users_table = removeUser(user, users_table);
                printf("User removed successfully\n\n");
            } 


        //show transaction book of user
        }else if(option == 5){
            User user = selectUser(users_table);
            if(user != NULL)
                showTransactions(transactions(user));
            printf("\n[0] Back");
            int q = getInputUser();
            if(q == 0)
                initialScreen();
            //else make sth (TODO) 
            

        //make transaction
        }else if(option == 6){
            printf("Select Who makes the transaction:");
            User user = selectUser(users_table);
            if(transactions(user) == NULL)
                Transactions t = createEmptyTransactions();
            //select the amount and the reciever of the transaction
            //assing the values 
            user = assignTransactions(user, t);
            //print the transaction maded


        //clear screen
        }else if(option == 8){
            User user = selectUser(users_table);
            initialScreen();


        }else if(option == 7){
            User user = selectUser(users_table);
            if(user != NULL){
                int a_balance;
                printf("Add balance:");
                scanf("%d", &a_balance);
                user = addBalance(user, a_balance);
                printf("Balance added successfully\n\n");
            }
        }
    }
    //delete [] also ArregloChars
    freeTable(users_table);
    return 0;
}



