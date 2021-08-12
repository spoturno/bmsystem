#include "include/user.h"
#include "include/utils.h"
#include "include/userTable.h"
#include "include/transactions.h"

#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sqlite3.h>

#define MAX_FIRST_NAME 32
#define MAX_LAST_NAME 32
#define MAX_ACC 9 


//function to read the test file and show results
void test(Table user_table){
    FILE * file = NULL; 
    char * line = NULL;
    char *ptr;
    size_t len = 0;
    ssize_t read;
    file = fopen("tests/01.in", "r");
    if(file == NULL){
        exit(EXIT_FAILURE);
    }
    while((read = getline(&line, &len, file)) != -1){
        int age, balance; 
        ArregloChars first_name = new char[MAX_FIRST_NAME];
        ArregloChars last_name = new char[MAX_FIRST_NAME];
        ArregloChars account = new char[MAX_ACC]; 

            ptr = strtok(line, " ");
            strcpy(first_name, ptr);

            ptr = strtok(NULL, " ");
            strcpy(last_name, ptr);

            ptr = strtok(NULL, " ");
            age = atoi(ptr);

            ptr = strtok(NULL, " ");
            balance = atoi(ptr);

            ptr = strtok(NULL, " ");
            strcpy(account, ptr);

        User user = createUser(first_name, last_name, age, account, balance);
        user_table = addUser(user, user_table);
    }
    fclose(file);
    if(line)
        delete line;
}

void initialScreen(){
    printf("\e[1;1H\e[2J");
    FILE * fp;
    int c;
    fp = fopen("screen.txt", "r");
    while(1){
        c = fgetc(fp) ;
        if(feof(fp))
            break;
        printf("%c", c);
    }
    fclose(fp);
}

int getInputUser(){
    int option;
    printf("\nEnter option:");
    scanf("%d", &option);
    return option;
}

User selectUser(Table table){
    ArregloChars account = new char[MAX_ACC];
    printTable(table);
    printf("Inser user account:");
    leerChars(account);
    User user = searchUser(table, account);
    if(user == NULL)
        printf("That account number doesn't exists\n");
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
            ArregloChars first_name = new char[MAX_FIRST_NAME];
            ArregloChars last_name = new char[MAX_FIRST_NAME];
            ArregloChars account = new char[MAX_ACC]; 
            printf("First Name:");
            scanf("%c", &temp);
            scanf("%[^\n]", first_name);
            printf("Last Name:");
            scanf("%c", &temp);
            scanf("%[^\n]", last_name);
            printf("Age:");
            age = leerNat();
            //printf("Iden:");
            //leerChars(account);
            //TODO: generate random account number 
            account = generateAccount();
            printf("Account balance:");
            scanf("%d", &balance);
            printf("\n");

            User user = createUser(first_name, last_name, age, account, balance);
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
        }else if(option == 6){
            User user = selectUser(users_table);
            if(user != NULL && transactions(user) != NULL)
                showTransactions(transactions(user));
            printf("\n\n[0] Back\n");
            int q = getInputUser();
            if(q == 0)
                initialScreen();
            //else make sth (TODO) 


            //make transaction
        }else if(option == 5){
            printf("Select Who makes the transaction\n");
            ArregloChars account = new char[MAX_ACC];
            while(1){ 
                printf("Insert sender:");
                leerChars(account);
                User user = searchUser(users_table, account);
                if(user == NULL){
                    printf("User with that Id doesn't exists\n");
                    printf("Try Again:\n");
                }
                else{
                    if(transactions(user) == NULL){
                        Transactions t = createEmptyTransactions();
                        user = assignTransactions(user, t);
                    }

                    // get amount and user_account:ArregloChars
                    nat amount; 
                    ArregloChars to_account = new char[MAX_ACC];
                    while(1){
                        printf("Reciever Account:");
                        leerChars(to_account);
                        User reciever = searchUser(users_table, to_account);
                        if(reciever == NULL){
                            printf("User with that Id doesn't exists\n");
                            printf("Try Again\n");
                        } else{
                            printf("Transaction Amount:");
                            scanf("%d", &amount);

                            if (balance(user) - amount < 0)
                                printf("Insufficient balance\n");
                            else{
                                Transaction to_add = createTransation(amount, to_account);
                                user = assignTransactions(user, addToTransactions(to_add, transactions(user)));
                                user = addBalance(user, -amount);
                                reciever = addBalance(reciever, amount);
                                printf("Transaction successfull\n");
                            }
                            break;
                        } 
                    }
                }
            }


            //clear screen
        }else if(option == 8){
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
        } else if(option == 99){
            test(users_table);
            printf("Random users added successfully.\n");
        }
    }
    //delete [] also ArregloChars
    freeTable(users_table);
    return 0;
}



