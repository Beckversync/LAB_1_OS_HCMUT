#include <stdio.h>
#include "calc_logic.h" 
#include <string.h>
#include <ctype.h>
int main() {
    double result;
    char operator;
    double num1, num2;
    char input[50]; 
    double HUGE_VAL=1000000000000;
    printf("Welcome to the calculator! \n");

    while (1) {
        printf(">> ");
        fgets(input, sizeof(input), stdin);
        
        // Remove newline character from input
        input[strcspn(input, "\n")] = '\0';

        // Exit if input is "EXIT"
        if (strcmp(input, "EXIT") == 0) {
            printf("Exiting the program.\n");
            break;
        }

        // Parse the input for calculation (handle the alphanumeric input)
        char num1_str[20], num2_str[20]; // Increase size of num2_str as well
        // Find the operator in the input
        char *operator_pos = strpbrk(input, "+-*/"); // Find first operator (+, -, *, /)
        if (operator_pos == NULL) {
            printf("Loi 0\n");
            continue;
        }
        
        operator = *operator_pos;  // Extract operator

        // Split input into num1 and num2_str
        // Copy num1_str before the operator
        strncpy(num1_str, input, operator_pos - input);
        num1_str[operator_pos - input] = '\0'; // Null terminate the string

        // Copy num2_str after the operator
        strcpy(num2_str, operator_pos + 1);

        // Check if num1_str contains a space and combine it if necessary
        if (strchr(num1_str, ' ')) {
            char combined_num1_str[20];  // Use a larger buffer for the combined num1_str
            int len = strlen(num1_str);
            int j = 0;
            // Combine num1_str by removing spaces
            for (int i = 0; i < len; i++) {
                if (num1_str[i] != ' ') {
                    combined_num1_str[j++] = num1_str[i];
                }
            }
            combined_num1_str[j] = '\0'; // Null-terminate the string
            printf("Combined num1_str: %s\n", combined_num1_str);
            strcpy(num1_str, combined_num1_str); // Copy the combined version back to num1_str
        }

        // Check if num2_str contains a space and combine it if necessary
        if (strchr(num2_str, ' ')) {
            char combined_num2_str[20];  // Use a larger buffer for the combined num2_str
            int len = strlen(num2_str);
            int j = 0;
            // Combine num2_str by removing spaces
            for (int i = 0; i < len; i++) {
                if (num2_str[i] != ' ') {
                    combined_num2_str[j++] = num2_str[i];
                }
            }
            combined_num2_str[j] = '\0'; // Null-terminate the string
            printf("Combined num2_str: %s\n", combined_num2_str);
            strcpy(num2_str, combined_num2_str); // Copy the combined version back to num2_str
        }

        // Convert num1 and num2 from alphanumeric to numeric
        num1 = alphanumericToNumeric(num1_str);
        num2 = alphanumericToNumeric(num2_str);

        // Check for errors in conversion
        if (num1 == -1 || num2 == -1 || num1>=HUGE_VAL || num2 >=HUGE_VAL) {
            printf("Loi 1\n");
            continue;
        }

        // Perform the calculation based on the operator
        switch (operator) {
            case '+':
                result = add(num1, num2);
                printf("Result: %.f\n", result);
                break;
            case '-':
                result = subtract(num1, num2);
                printf("Result: %.f\n", result);
                break;
            case '*':
                result = multiply(num1, num2);
                printf("Result: %.f\n", result);
                break;
            case '/':
                if (num2 != 0) {
                    result = divide(num1, num2);
                    printf("Result: %.2f\n", result);
                } else {
                    printf("MATH ERROR\n");
                }
                break;
            default:
                printf("Loi 2\n");
                continue;
        }
    }

    return 0;
}
