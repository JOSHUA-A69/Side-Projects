#include <stdio.h>
#define AMOUNT 750.0


// function to display balance
void displayBalance(float current_balance, float reduced_balance, float increased_balance) {
    printf("\nCurrent balance: %.2f\n", current_balance);
    printf("Reduced balance: %.2f\n", reduced_balance);
    printf("Increased balance: %.2f\n", increased_balance);
}
// function to deposit amount
void depositAmount(float *current_balance, float *increased_balance) {
    double amount_deposit;
    char flag = 1;
   do{
        printf("\nEnter amount to deposit: ");
        if (scanf("%lf", &amount_deposit) != 1) {
            printf("Invalid input. Please enter a valid number.\n");
            flag = 1;
            break;
        }
        if (amount_deposit <= 0) {
            printf("Amount must be greater than zero.\n");
            continue;
        }
        *current_balance += amount_deposit;
        *increased_balance += amount_deposit;
        break;
    }while(flag == 1 || amount_deposit <= 0);
}
// function to withdraw amount
void withdrawAmount(float *current_balance, float *reduced_balance) {
    double amount_withdraw;
    char flag = 1;
     do{
        printf("\nEnter amount to withdraw: ");
        if (scanf("%lf", &amount_withdraw)!=1){
            printf("Invalid input. Please enter a valid number.\n");
            flag = 1;
            break;
            
        }
        if (amount_withdraw <= 0 || amount_withdraw <= 750) {
            printf("amount withdrawn should not cause the balance to below 500 nor should be 0 or less.\n");
            continue;
        } else if (amount_withdraw < *current_balance - amount_withdraw) {
            
        }
        *current_balance -= amount_withdraw;
        *reduced_balance += amount_withdraw;
        break;
    }while(flag == 1 || amount_withdraw <= 0 || amount_withdraw <= 750 || amount_withdraw < *current_balance - amount_withdraw); 
}
int main(){
    int ans;
    float current_balance = AMOUNT;
    float reduced_balance = 0.0;
    float increased_balance = 0.0;
    
    while (1) {
        printf("ATM PROGRAM\n\n");
        printf("1. Check Balance\n2. Deposit\n3. Withdraw\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ans);
        
        if (ans == 0) {
            break;
        }
        
        
        if (ans == 1) {
            displayBalance(current_balance, reduced_balance, increased_balance);
        }
        
        if (ans == 2) {
            depositAmount(&current_balance, &increased_balance);
        }
        
        if (ans == 3) {
            withdrawAmount(&current_balance, &reduced_balance);
       } 
    }
     return 0;
  }
    
    