#include<stdio.h>
#include<string.h>
#include<stdlib.h>




//user 
struct user {
    char accId[8];
    int phoneNumber[6];
    int password[6];
    float balance;
};

int main(){
    struct user usr;
    int choice,res;
    char cond = 'y';
    int amount;

    FILE *fp,*fpt;
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
        int length = strlen(usr.password);
        if(length>6 || length<6){
            printf("\nThe password must be 6 digits long, try again.\n");
            exit(0);
        }
        usr.balance=0;

        //store info in file, for each user there is file of which name is account ID
        strcpy(userFileName,usr.accId);
        fp = fopen (strcat(userFileName,".dat"), "w"); //join two strings
        fwrite(&usr, sizeof(usr),1,fp);
        if(fwrite != 0){
            printf("\n\n Account Registered!");
        }else{
            printf("\n Error Something Gone Wrong!");
        }
    }else if(choice == 2){
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
            fread(&usr, sizeof(struct user),1,fp);
            fclose(fp);
            if(!strcmp(pw,usr.password)){
                system("clear");
                while(cond == 'y'){
                printf("\nYou are logged it as: %s",usr.accId);
                printf("\nPlease choose an action");
                printf("\nPress 1 to Deposit");
                printf("\nPress 2 to Withdraw");
                printf("\nPress 3 to Check Balance");
                printf("\nPress 4 to transfer money\n");
                scanf("%d",&res);
                switch(res){
                    case 1: //Deposit
                        system("clear");
                        printf("\nWrite an amount you want to deposit:");
                        scanf("%d", &amount);
                        usr.balance += amount;
                        fp = fopen(userFileName,"w");
                        fwrite(&usr,sizeof(struct user),1,fp);
                        if(fwrite!=0){printf("\nDeposited succesfully %d $\n", amount);}
                        fclose(fp);
                        break;

                    case 2://Withdraw
                        system("clear");
                        printf("\nType an amount you want to withdraw:");
                        scanf("%d",&amount);
                        if(amount<20){
                            printf("\nMinimum withdraw is 20$");
                        }else if(amount>usr.balance){
                            printf("\nInsufficent balance.");
                        }else{
                            usr.balance -= amount;
                            fp = fopen(userFileName,"w");
                            fwrite(&usr,sizeof(struct user),1,fp);
                            if(fwrite!=0){printf("\nWithdraw has been completed succefully");
                            fclose(fp);
                        }
                        }
                        
                        break;
                        

                    case 3://Check balance
                        system("clear");
                        printf("\n***Your balance is:%.2f$***\n", usr.balance);
                        break;
                    
                    case 4:
                        printf("Please enter the account ID to trasnfer :\t");
						scanf("%s",id);
						printf("Enter the amount to transfer:\t");
						scanf("%d",&amount);
						if(amount > usr.balance) printf("\nSorry insufficent balance");
						else {
							fpt = fopen(strcat(id,".dat"),"r");
							if(fpt==NULL) printf("Sorry number is not registered");
							else {
								fread(&usr,sizeof(struct user),1,fpt);
								fclose(fp);
							
								usr.balance += amount;
								
								fpt = fopen(id,"w");
								fwrite(&usr,sizeof(struct user),1,fpt);
								if(fwrite != 0){
								// 	printf("ACcount:%s",usr.ac);
								// printf("\npassword%s",usr.password);
								// printf("\nphone%s",usr.phone);
								// printf("\nbalance%f",usr.balance);
									printf("Your trasfer is completed. You have trasnfered %d to %s",amount,usr.accId);
									fclose(fpt);
									usr.balance -= amount;
									strcpy(userFileName,usr.accId);
									fp = fopen(strcat(userFileName,".dat"),"w");
									fwrite(&usr,sizeof(struct user),1,fp);
									fclose(fp);
								}
							}
						}
						break;
                        








                    default:
                    break;
                    }
                    printf("\nDo you want to continue? Y/N:");
                    scanf("%s",&cond);
                    

                }
            }else{
                printf("\nPassword is not correct!\n");
            }
        
        }

    }
return 0;
}       
