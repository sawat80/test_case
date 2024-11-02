#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <num1> <operator> <num2>\n", argv[0]);
        return 1; // Return error if incorrect number of arguments
    }

    // Convert arguments to numbers
    double num1 = atof(argv[1]);
    double num2 = atof(argv[3]);
    char operator = argv[2][0];
    double result;

    // Perform the operation based on the operator
    switch (operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                printf("Error: Division by zero!\n");
                return 1;
            }
            break;
        default:
            printf("Error: Invalid operator! Use +, -, *, or /.\n");
            return 1;
    }

    // Print the result
    printf("Result: %.2f\n", result);
    return 0; // Successful execution
}
