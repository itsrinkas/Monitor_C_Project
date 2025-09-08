/**
 * @file main.c
 *
 * <b>CE4703 Computer Software 3</b>
 * <b>Assignment 1</b><br/>
 * This file contains the main function that provides a menu
 * to execute the different Menu Functions (MF1, MF2, MF3, MF4).
 *
 *
 * @author Karyna Enato (23329831)
 * @date 30.10.2024
 */

 // include system header files
#include <stdio.h>

 // Function prototypes for Menu Functions
void MF1();
void MF2();
void MF3();
void MF4();

/**
 * @brief Main function to display a menu and perform actions based on user input.
 *
 * The main function presents a menu to the user with options to perform different tasks or exit the program.
 *
 * @return int Returns 0 to indicate successful program termination.
 */
int main() {
    int choice;

    // Loop until the user chooses to exit
    do {
        // Display the menu options
        printf("\nMenu:\n");
        printf("1. Perform MF1\n");
        printf("2. Perform MF2\n");
        printf("3. Perform MF3\n");
        printf("4. Perform MF4\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        // Read the user's choice
        scanf_s("%d", &choice);

        // Execute the corresponding function based on the user's choice
        switch (choice) {
        case 1:
            MF1(); // Call Menu Function 1
            break;
        case 2:
            MF2(); // Call Menu Function 2
            break;
        case 3:
            MF3(); // Call Menu Function 3
            break;
        case 4:
            MF4(); // Call Menu Function 4
            break;
        case 5:
            printf("\nExiting program.\n"); // Exit message
            break;
        default:
            printf("\nInvalid choice. Please try again.\n"); // Invalid choice message
        }
    } while (choice != 5); // Repeat until the user selects "Exit"

    return 0; // Return 0 to indicate successful termination
}
