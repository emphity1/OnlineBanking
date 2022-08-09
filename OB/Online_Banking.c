#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int const ACCOUNT_ID = 100;
int const PHONE_NUMB = 10;
int const PW = 20;




//user 
struct user {
    char accId[ACCOUNT_ID];
    char phoneNumber[PHONE_NUMB];
    char password[PW];
    float balance;
};

int main(){
    struct user usr;

    printf("\nWhat are you looking for?");
    printf("\n\n1. Register an account");
    printf("\n2. Login to account");


}
