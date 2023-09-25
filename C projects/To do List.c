#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // Include the time library

#define MAX_TASK 10
#define MAX_TASK_LENGTH 100 // Increased to accommodate date and time

int taskCount = 0;
char task[MAX_TASK][MAX_TASK_LENGTH];

void clearScreen() {
    system("cls");
}

void addTask() {
    clearScreen();
    if (taskCount < MAX_TASK) {
        printf("Enter a task: ");
        scanf(" %[^\n]", task[taskCount]);
        
        // Get the current date and time
        time_t now;
        struct tm *local_time;
        char time_str[50];
        
        time(&now);
        local_time = localtime(&now);
        strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", local_time);
        
        // Append date and time to the task
        snprintf(task[taskCount], sizeof(task[taskCount]), "%s (Added on %s)", task[taskCount], time_str);
        
        taskCount++;
        printf("Task added: %s\n", task[taskCount - 1]);
    } else {
        printf("The list is full, cannot add more tasks.\n");
    }
    printf("Press enter to continue...");
    getchar();
}

void displayTask() {
    clearScreen();
    printf("To-Do List:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. %s\n", i + 1, task[i]);
    }
    printf("Press enter to continue...");
    getchar();
}

void deleteTaskAtIndex(int index) {
    for (int i = index; i < taskCount - 1; i++) {
        strcpy(task[i], task[i + 1]);
    }
    taskCount--;
}

void deleteTask() {
    clearScreen();
    if (taskCount == 0) {
        printf("There are no tasks to delete.\n");
    } else {
        printf("Select a task to delete (or press 'x' to exit):\n");
        for (int i = 0; i < taskCount; i++) {
            printf("%d. %s\n", i + 1, task[i]);
        }

        char choice;
        printf("Enter the index of the task to delete or 'x' to exit: ");
        scanf(" %c", &choice);

        if (choice == 'x' || choice == 'X') {
            return;
        }

        int index = choice - '0';
        if (index >= 1 && index <= taskCount) {
            deleteTaskAtIndex(index - 1);
            printf("Task deleted.\n");
        } else {
            printf("Invalid task index.\n");
        }
    }
    printf("Press enter to continue...");
    getchar();
}

int main() {
    int choice = 0;

    while (1) {
        clearScreen();
        printf("1. Add task\n");
        printf("2. Display Task\n");
        printf("3. Delete task\n");
        printf("4. Quit\n");

        printf("Enter your choice: ");
        int inputStatus = scanf("%d", &choice);

        if (inputStatus != 1) {
            clearScreen();
            printf("Invalid input. Please enter a valid numeric choice.\n");
            printf("Press enter to continue...");
            getchar(); // Consume newline character
        } else {
            getchar(); // Consume newline character

            switch (choice) {
                case 1:
                    addTask();
                    break;
                case 2:
                    displayTask();
                    break;
                case 3:
                    deleteTask();
                    break;
                case 4:
                    printf("Thank you for using the To-Do List. Have a great day!\n");
                    printf("Goodbye!\n");
                    break;
                default:
                    printf("Invalid choice. ");
                    break;
            }

            if (choice < 1 || choice > 4) {
                printf("Please select a valid option from the menu.\n");
            }

            getchar(); 

            if (choice == 4) {
                break;
            }
        }
    }

    return 0;
}