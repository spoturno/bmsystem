#include "../include/utils.h"
#include "../include/user.h"
#include "../include/timer.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_UID 10
#define MAX_NAME 32

struct _rep_user{
    ArregloChars account;
    ArregloChars first_name;
    ArregloChars last_name;
    nat age;
    User next;
    struct tm *time;
    int balance;
    Transactions trc;
};

User createUser(ArregloChars first_name,ArregloChars last_name,nat age, int balance){
    User user = new _rep_user;
    user->age = age;
    user->account = generateAccount();
    user->first_name = first_name;
    user->last_name = last_name;
    user->next = NULL;
    user->balance = balance;
    user->time = getCurrentTime();
    user->trc = NULL;
    return user;
}

User next(User user)
{
    return user->next;
}

//Reuquires Update (TODO)
//TODO: modify last name:
User modifyUser(User user){
    nat option;
    printf("[1] Account\n[2] Name\n[3] Age\n[4] Balance\n");
    printf("Select what you want to modify:");
    scanf("%d", &option);

    if(option == 1){
        ArregloChars new_account = new char[MAX_UID];
        printf("Inser new account number:");
        leerChars(new_account);
        ArregloChars temp = user->account;
        user->account = new_account;
        //delete[] temp;

    } else if(option == 2){
        ArregloChars new_first_name = new char[MAX_NAME];
        printf("Insert new Name");
        leerChars(new_first_name);
        ArregloChars temp = user->first_name;
        user->first_name = new_first_name;
        delete[] temp;

    } else if(option == 3){
        nat new_age;
        printf("Insert new Age:");
        new_age = leerNat();
        user->age = new_age;

    } else if(option == 4){
        printf("This will only change (replace) the current user balance\n");
        printf("To add balance go option 7 in initial screen\n");
        printf("New balance:");
        int new_balance; 
        scanf("%d", &new_balance);
        user->balance = new_balance;
    }
    return user;
}

User insertNext(User user, User newUser){
    User temp = user;
    while(user->next != NULL)
        temp = user->next;
    temp->next = newUser;
    return user;
}

void freeUser(User user){
    if(user != NULL){
        while(user->next != NULL){
            User temp = user;
            user = user->next;
            freeTransactions(transactions(temp));
            delete temp;
        }
    }
    delete user;
}

ArregloChars account(User user){
    return user->account;
}

int age(User user){
    return user->age;
}

int balance(User user){
    return user->balance;
}

User addBalance(User user, int a_balance){
    user->balance+=a_balance;
    return user;
}

ArregloChars first_name(User user){
    return user->first_name;
}

ArregloChars last_name(User user){
    return user->last_name;
}

struct tm * userAdmissionDate(User user){
    return user->time;
}


void printUserChain(User user){
    User temp = user;
    while(temp->next != NULL){
        temp = temp->next;
        printf("| %-15s | %-15s | %-15s | %-4d | $%-8d | -%d/%d/%d  |\r\n", temp->account, temp->first_name, temp->last_name, temp->age, temp->balance, temp->time->tm_yday, temp->time->tm_mon, temp->time->tm_year); 
    }
    temp = NULL;
    delete temp;
}

User refNextUser(User user, User ref_to){
    user->next = ref_to;
    return user;
}

Transactions transactions(User user){
    return user->trc;
}

User assignTransactions(User user,Transactions t){
    user->trc = t;
    return user;
}

// move to main.cpp to used macros?
ArregloChars generateAccount(){
    srand(time(NULL));
    ArregloChars str = new char[9];
    size_t max_acc = 9;
    if(max_acc){
        max_acc--;
        for(size_t n = 0; n < max_acc; n++){
            int numr = rand() % 10;
            str[n] = numr + '0';
        }
        str[max_acc] = '\0';
    }
    return str;
}
