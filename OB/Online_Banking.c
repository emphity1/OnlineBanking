#include<stdio.h>
#include<string.h>
#include<stdlib.h>




//user 
struct user {
    char accId[8];
    char phoneNumber[6];
    char password[6];
    float balance;
};

int main(){
    struct user usr;
    int choice,res;
    char cond = 'y';
    double amount;

    FILE *fp;
    char userFileName[50],pw[20],id[20];
    

    printf("\nWhat are you looking for?");
    printf("\n\n1. Register an account");
    printf("\n2. Login to an account\n");

    printf("\nWaiting....\n");
    scanf("%d", &choice);

     
    if(choice == 1){ //Registering an account
        system("clear");
        printf("\n Enter your Account Id(max 8 digits):");
        scanf("%s", usr.accId);
        printf("\n Enter your Phone Number(8 digits long):");
        scanf("%s", usr.phoneNumber);
        printf("\n Enter your password(6 digits long) :");
        scanf("%s",usr.password);
        usr.balance=0;

        //store info in file, for each user there is file of which name is account ID
        strcpy(userFileName,usr.accId);
        fp = fopen (strcat(userFileName,".dat"), "w"); //join two strings
        fwrite(&usr, sizeof(struct user),1,fp);
        if(fwrite != 0){
            printf("\n\n Account Registered!");
        }else{
            printf("\n Error Something Gone Wrong!");
        }
        fclose(fp);
    }
    if(choice == 2){
        system("clear");
        printf("\n\n Enter your account id: ");
        scanf("%s",id);
        printf("\n Enter your password: ");
        scanf("%s", pw);
        int length = strlen(pw);
        if(length>6 || length<6){
            printf("\nThe password must be 6 digits long, try again.\n");
            exit(0);
        }
        strcpy(userFileName,id);
        fp = fopen(strcat(userFileName, ".dat"),"r");
        if(fp==NULL){
            printf("\n Account is not registered");
        }else{
            while(cond == 'y'){
                system("clear");
                printf("\n You are logged it as:%s",usr.accId);
                printf("\nPlease choose an action");
                printf("\nPress 1 to Deposit");
                printf("\nPress 2 to Withdraw");
                printf("\nPress 3 to Check Balance");
                scanf("%d",&res);
                switch(res){
                    case 1: //Deposit
                        system("clear");
                        printf("\nChoose an amount you want to deposit");
                        scanf("%f", &amount);
                        usr.balance += amount;
                        fp = fopen(userFileName,"w");
                        fwrite(&usr,sizeof(struct user),1,fp);
                        if(fwrite!=0){printf("\nDeposited succesfully\n");}
                        fclose(fp);
                        break;

                    case 2://Withdraw
                        printf("\nType an amount you want to withdraw: %f",&amount);
                        if(amount<20){
                            printf("\nMinimum withdraw is 20.");
                        }else if(amount>usr.balance){
                            printf("\nInsufficent balance.");
                        }else{
                            usr.balance -= amount;
                        }
                        fp = fopen(userFileName,"w");
                        fwrite(&usr,sizeof(struct user),1,fp);
                        if(fwrite!=0){printf("\nWithdraw has been completed succefully");
                        fclose(fp);
                        }
                        break;
                        

                    case 3://Check balance
                        printf("\nYour balance is:%.2f", usr.balance);
                        break;
                }

            }
        }

        
        fread(&usr,sizeof(struct user),1,fp);
        fclose(fp);

        if(!strcmp(pw,usr.password)){
            printf("\n Password is correct! You're logged in....");
        }else{
            printf("\n Password is not correct!");
        }
    }

}       
