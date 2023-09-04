#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

// Define the number of currencies
#define NUM_CURRENCIES 149

// Declare arrays for storing currency names and rates
char* currency_names[] = {"USD", "EUR", "JPY", "GBP", "AUD", "CAD", "CHF", "CNY", "HKD",
                          "INR", "KRW", "MXN", "MYR", "NOK", "NZD", "SEK", "SGD", "THB", "TWD",
                          "AED", "BRL", "CLP", "CZK", "DKK", "HUF", "IDR", "ILS", "PHP", "PLN",
                          "RON", "RUB", "SAR", "TRY", "ZAR", "ARS", "BGN", "BHD", "BND", "COP",
                          "EGP", "HRK", "ISK", "JOD", "KWD", "LKR", "MAD", "OMR", "PEN", "QAR",
                          "TND", "UAH", "UYU", "VEF", "AFN", "ALL", "AMD", "AOA", "AZN", "BAM",
                          "BBD", "BDT", "BIF", "BWP", "BYN", "BZD", "CDF", "CVE", "DJF",
                          "DOP", "ERN", "ETB", "FJD", "FKP", "GEL", "GHS", "GIP", "GMD",
                          "GNF", "GTQ", "GYD", "HNL", "HTG", "IQD", "IRR", "JMD", "KES", "KGS",
                          "KHR", "KMF", "KPW", "KYD", "KZT", "LAK", "LBP", "LRD", "LSL", "LYD",
                          "MGA", "MKD", "MMK", "MNT", "MOP", "MUR", "MWK", "NAD", "NGN",
                          "NIO", "NPR", "PAB", "PGK", "PYG", "RWF", "SBD", "SCR", "SDG",
                          "SHP", "SLL", "SOS", "SRD", "STD", "SVC", "SZL", "TJS", "TMT", "TOP",
                          "TTD", "TZS", "UGX", "UZS", "VND", "VUV", "WST", "XAF", "XCD", "XOF",
                          "XPF", "YER", "ZMW", "AWG", "BMD", "BOB", "BSD",
                          "CRC", "CUP", "MRO", "PKR", "SYP", "VES", "BTC"
                         };


double currency_rates[] = {1.000000	, 0.92019, 138.45, 0.80206, 1.4978, 1.3537, 0.8972, 6.9590, 7.8427, 82.2380,
                           1334.7, 17.558, 4.5006, 10.6490, 1.6096, 10.371, 1.3386, 33.770, 30.812, 3.6725,
                           4.5358, 785.307, 21.723, 6.8517, 340.40, 14815, 3.6513, 55.721, 4.1561, 4.92344,
                           78.210, 3.7500, 19.666, 19.042, 229.92, 1.8009, 0.37600, 1.3388, 4557.0, 30.874, 6.9378, 138.58,
                           0.70900, 0.30699, 313.43, 10.096, 0.38494, 3.6609, 3.6400, 3.0669, 36.922, 39.089, 2534900, 88.339,
                           102.19,  387.86, 512.93, 1.7000, 1.8013, 2.0000, 107.65, 2826.0, 13.557, 2.4999, 2.0203, 2041.3, 101.56,
                           177.80, 54.688, 15.000, 54.700, 2.2196, 0.80282, 2.5245, 11.712, 0.80270, 59.851, 8617.0, 7.8140, 211.66,
                           24.635, 145.91, 1315.5, 42392, 155.15, 136.99, 87.298, 4124.9, 452.92, 899.97, 0.82064, 448.67, 87.299, 17574,
                           15025, 166.55, 19.121, 4.7737, 4403.1, 56.653, 2106.2, 3488.9, 8.0780, 45.372, 1029.3, 19.127, 460.50, 36.661,
                           131.59, 1.0000, 3.5336, 7246.7, 1121.2, 8.3805, 13.898, 0.80238, 22785, 564.41, 36.990, 22531, 8.7500, 19.127,
                           10.954, 3.5035, 2.3470, 6.8003, 2355.9, 3741.0, 11411, 23524, 119.34, 2.7128, 603.81, 2.7019, 603.77, 109.84, 250.36,
                           18.413, 1.7900, 1.0000, 6.9250, 1.0000, 537.66, 24.054, 343.42, 288.35, 2512.0, 25.353, 0.000036759
                          };



// Function for converting a given amount from one currency to another
void convert_currency(double amount, int from_index, int to_index)
{
    // Compute the converted amount using the currency rates
    double converted_amount = amount * currency_rates[to_index] / currency_rates[from_index];
    // Print the results
    printf("==========================\n");
    printf("Result\n%.5f %s  = %.5f %s\n", amount, currency_names[from_index], converted_amount, currency_names[to_index]);
    printf("==========================\n\n");
}

// Function for finding the index of a given currency code in the array
int find_currency_index(char* currency_code)
{
// Loop through all currency names and compare them to the given code
    for (int i = 0; i < NUM_CURRENCIES; i++) {
        if (strcmp(currency_code, currency_names[i]) == 0) {
            return i;
        }
    }
// If the code was not found, return -1
    return -1;
}

// Function for displaying all the currencies and their rates
void display_all_currencies()
{
    // Print the header
    printf("==============================\n");
    printf("All Currencies and their rates\n");
    printf("as of MAY 2023\n");
    printf("==============================\n");
    // Loop through all currencies and print their names and rates
    for (int i = 0; i < NUM_CURRENCIES; i++) {
        printf("%s= %.5f\n", currency_names[i], currency_rates[i]);
    }
}

int main()
{

    int choice;
    double amount;
    char from[4], to[4];

    while (1) {
        system("cls"); // clear the screen
        // Display the menu and get the user's choice
        printf("==============================\n");
        printf("CURRENCY CONVERTER CALCULATOR\n");
        printf("==============================\n");
        printf("1. Convert currencies\n");
        printf("2. Display all currencies\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        system("cls");
        if (choice == 1) {
            // Prompt the user to enter the amount and the two currency codes
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("Enter the amount to convert \n");
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n=");
            scanf("%lf", &amount);

            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("Enter the currency code to convert from (in uppercase or lowercase)\n");
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n-");
            scanf("%s", from);

            // Convert the input to uppercase for consistency
            for (int i = 0; from[i]; i++) {
                from[i] = toupper(from[i]);
            }

            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("Enter the currency code to convert to (in uppercase or lowercase)\n");
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n-");
            scanf("%s", to);

            // Convert the input to uppercase for consistency
            for (int i = 0; to[i]; i++) {
                to[i] = toupper(to[i]);
            }

            // Find the indices of the two currencies and convert the amount
            int from_index = find_currency_index(from);
            int to_index = find_currency_index(to);
            if (from_index == -1 || to_index == -1) {
                printf("Invalid currency code\n\n");
            } else {
                convert_currency(amount, from_index, to_index);
            }

            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("Press enter to go back to menu options\n");
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

            getchar(); // clear the newline character from the input buffer
            getchar(); // wait for the user to press enter

            system("cls");
        } else if (choice == 2) {
            // Display all currencies
            display_all_currencies();
            printf("========================================\n");
            printf("Press enter to go back to menu options\n");
            printf("========================================\n");

            getchar(); // clear the newline character from the input buffer
            getchar(); // wait for the user to press enter

            system("cls");
        } else if (choice == 3) {
            // Exit the program
            printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
            printf("Developed by:JOSHUA RUSSEL UY\n");
            printf("Thank you for using this Program!\n");
            printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
            return 0;

            system("cls");
        } else {
            // Invalid choice
            printf("Invalid choice\n\n");
            printf("========================================\n");
            printf("Press enter to go back to menu options\n");
            printf("========================================\n");

            getchar(); // clear the newline character from the input buffer
            getchar(); // wait for the user to press enter
            system("pause");
        }
    }
}
