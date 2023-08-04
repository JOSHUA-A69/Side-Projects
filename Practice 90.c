#include <stdio.h>
 void printAsterisks(int n) {
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("*");
        }
        printf("\n");
    }
}

void count_OddEven(int num, int *even_count, int *odd_count){
    int even = 0;
    int odd  = 0;
    while(num != 0){
        if (num % 2 == 0) {
            even++;
        }
        else {
            odd++;
        }
        scanf("%d", &num); 
    }
    *even_count = even;
    *odd_count = odd;
}
#define DEFAULT_PASSWORD 12345

int validatePassword(int password){
return password == DEFAULT_PASSWORD;
} 



int main() {
  int ans;
  int n, i, j;
  int num, even_count = 0, odd_count = 0;
  int enteredPassword=12345;
  
  while (1) {
    printf("\n-- MENU --\n");
    printf("Display menu again: [0]\n");
    printf("Display asterisk: [1]\n");
    printf("Input odd and even numbers: [2]\n");
    printf("Display password/passcode: [3]\n");
    printf("If input is more than 4 the program will end\n");
    printf("Enter choice: ");
    scanf("%d", &ans);
    
    if (ans == 0) {
      continue;
    }
    if (ans >= 4) {
      printf("Invalid input.\n");
      break;
    }
    if (ans == 1) {
      printf("Enter a number: ");
      scanf("%d", &n);
      printAsterisks(n);
      printf("\n");
    }
    if (ans == 2) {
    printf("Enter numbers. Input 0 to end: \n");
    scanf("%d", &num);
    count_OddEven(num, &even_count, &odd_count);
    printf("\nNumber of odd numbers entered: %d\n", odd_count);
    printf("Number of even numbers entered: %d\n", even_count);
    }
    if (ans == 3) {
   do {
    printf("Please enter your password: ");
    scanf("%d", &enteredPassword);
    if(enteredPassword != DEFAULT_PASSWORD){
    	printf("Invalid Password\n");
	}
  } while (!validatePassword(enteredPassword));
   printf("Access Granted!");
  }
 return 0;
 }
 }
