#include <stdio.h>
#include <stdlib.h>

// Function to calculate the square root approximation
double sqrt_approx(double n) {
    if (n < 0) {
        return -1; // Return -1 for negative input to indicate an error
    }

    double tolerance = 0.00001; // Set the tolerance level for approximation
    double x = n / 2.0; // Initial guess

    // Iterate until the difference is smaller than the tolerance
    while ((x * x - n) > tolerance || (n - x * x) > tolerance) {
        x = 0.5 * (x + n / x); // Update x using the formula
    }

    return x;
}

int main(int argc, char *argv[]) {
    // Check if the user provided a command-line argument
    if (argc != 2) {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }

    // Convert the command-line argument to a double
    double number = atof(argv[1]);
    double result = sqrt_approx(number);

    if (result == -1) {
        printf("Error: Negative input\n");
    } else {
        printf("The square root approximation of %.5f is %.5f\n", number, result);
    }

    return 0;
}

