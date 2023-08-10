#include <stdio.h>
#include <stdlib.h>
#define Amount 0.00

void checkBalance(float currentBalance, float increasedBalance, float reducedBalance){
	printf("\n\nCurrent Balance is %.2f\n",currentBalance);
	printf("Increased Balance is %.2f\n",increasedBalance);
	printf("Reduced Balance is %.2f\n",reducedBalance);
}
void depositAmount(float *currentBalance , float *increasedBalance){
	double amountdeposit;
	do{
		printf("Enter Amount to Deposit:");
		if (scanf("%lf", &amountdeposit) != 1) {
            printf("Invalid input. Please enter a valid number.\n");
            while (getchar() != '\n');
            continue;
        
	}
	if(amountdeposit <= 0){
		printf("Amount must be greater than zero.\n");
        continue;
	}
	*currentBalance += amountdeposit;
	*increasedBalance += amountdeposit;
	break;
} while(1);
}
void withdrawAmount(float *currentBalance, float *reducedBalance){
	double amountwithdraw;
	do{
		printf("Enter Amount to Withdraw:");
		 if (scanf("%lf", &amountwithdraw) != 1) {
            printf("Invalid input. Please enter a valid number.\n");
            while (getchar() != '\n');
            continue;
	}
	if(amountwithdraw <= 0){
		 printf("Amount must be greater than zero.\n");
            continue;
        } else if (amountwithdraw > *currentBalance) {
            printf("Insufficient balance.\n");
            continue;
	}
	*currentBalance -= amountwithdraw;
	*reducedBalance += amountwithdraw;
	break;	
}while(1);
}

  int main(){
   int ans;
    float currentBalance = Amount;
    float increasedBalance = 0.0;
    float reducedBalance = 0.0;
    	
    	while (1){
    	system("cls");
        printf(" ATM  Program \n");
        printf("1. Check Balance\n2. Deposit\n3. Withdraw\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ans);
        
        if (ans == 0) {
            break;
        }
        
        if (ans < 1 || ans > 3) {
        printf("Invalid Input\n");
        system("pause");
        break;
        }
    if(ans == 1){
    	checkBalance(currentBalance, increasedBalance, reducedBalance);
	}
	if(ans == 2){
		depositAmount(&currentBalance, &increasedBalance);
	}
	if(ans == 3){
		withdrawAmount(&currentBalance, &reducedBalance);
	}
	system("pause");	   
 }
   return 0;
 }
