#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

// Define the symbols and their respective counts and values
#define SYMBOL_COUNT 4
#define SYMBOLS          { '$', '#', '&', '%' }
#define SYMBOLS_VALUES    { 2,   4,   6,   8 }

// Function to deposit money
float deposit() {
    float depositAmount;
    while (1) {
        printf("Enter a deposit amount in PHP: ");
        if (scanf("%f", &depositAmount) != 1 || depositAmount <= 0) {
            printf("Invalid deposit amount, please try again.\n");
            while (getchar() != '\n'); // Clear input buffer
        } else {
            printf("You have successfully deposited PHP %.2f.\n", depositAmount);
            return depositAmount;
        }
    }
}

// Function to get the number of lines to bet on
int getNumberOfLines() {
    int numberOfLines;
    while (1) {
        printf("Enter the number of lines to bet on (1-3): ");
        if (scanf("%d", &numberOfLines) != 1 || numberOfLines <= 0 || numberOfLines > 3) {
            printf("Invalid number of lines, please try again.\n");
            while (getchar() != '\n'); // Clear input buffer
        } else {
            return numberOfLines;
        }
    }
}

// Function to get the bet amount per line
float getBet(float balance, int lines) {
    float bet;
    while (1) {
        printf("Enter the bet per line in PHP (Maximum bet: PHP %.2f): ", balance);
        if (scanf("%f", &bet) != 1 || bet <= 0 || bet > balance / lines) {
            printf("Invalid bet, please try again.\n");
            while (getchar() != '\n'); // Clear input buffer
        } else {
            return bet;
        }
    }
}

// Function to spin the slot machine and return the reels
void spin(char reels[COLS][ROWS]) {
    char symbols[] = SYMBOLS; // Symbols pool
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            int randomIndex = rand() % SYMBOL_COUNT; // Generate a random index
            reels[i][j] = symbols[randomIndex]; // Assign a symbol to the reel
        }
    }
}

// Function to check if the user won and calculate winnings
float getWinnings(char rows[ROWS][COLS], float bet, int lines) {
    float winnings = 0;

    for (int row = 0; row < lines; row++) {
        char symbols[COLS];
        int allSame = 1;

        for (int col = 0; col < COLS; col++) {
            symbols[col] = rows[row][col];
            if (col > 0 && symbols[col] != symbols[0]) {
                allSame = 0;
                break;
            }
        }
        
        if (allSame) {
            char symbol = symbols[0];
            switch (symbol) {
                case '$':
                    winnings += bet * 2;
                    break;
                case '#':
                    winnings += bet * 4;
                    break;
                case '&':
                    winnings += bet * 6;
                    break;
                case '%':
                    winnings += bet * 8;
                    break;
                default:
                    // Handle unknown symbols or set a default value
                    break;
            }
        }
    }
    return winnings;
}

// Function to transpose the reels
void transpose(char reels[COLS][ROWS], char transposed[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            transposed[i][j] = reels[j][i];
        }
    }
}

// Function to print the rows
void printRows(char rows[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c | ", rows[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    float balance = deposit(); // Update the balance variable

    while (1) {
        printf("You have a balance of PHP %.2f\n", balance);
        int numberOfLines = getNumberOfLines();
        float bet = getBet(balance, numberOfLines);
        balance -= bet * numberOfLines;

        char reels[COLS][ROWS];
        spin(reels);

        char rows[ROWS][COLS];
        transpose(reels, rows);
        printRows(rows);

        float winnings = getWinnings(rows, bet, numberOfLines);
        balance += winnings;
        printf("You won PHP %.2f\n", winnings);

        if (balance <= 0) {
            printf("You ran out of money!\n");
            break;
        }

        char playAgain;
        printf("Do you want to play again (y/n)? ");
        while (1) {
            while (getchar() != '\n'); // Clear input buffer
            playAgain = getchar();
            if (playAgain == 'y' || playAgain == 'n') {
                break;
            } else {
                printf("Invalid input, please enter 'y' or 'n': ");
            }
        }

        if (playAgain != 'y') {
            break;
        }
    }

    return 0;
}
