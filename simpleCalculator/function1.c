    #include <stdio.h>
// Function to calculate sum and average
int calculateSumAndAverage(int num1, int num2, int *sum, float *average) {
    if (num1 < 0 || num2 < 0) {
        return 0; // Return 0 if inputs are invalid (negative numbers)
    }
    *sum = num1 + num2;                 // Calculate sum
    *average = *sum / 2.0;              // Calculate average
    return 1;                           // Return 1 indicating success
}
int main() {
    int number1, number2;
    int sum;
    float average;
    // Input two integers
    printf("Enter two integers: ");
    scanf("%d %d", &number1, &number2);
    // Call the function
    if (calculateSumAndAverage(number1, number2, &sum, &average)) {
        // Print the results if calculation was successful
        printf("Sum: %d\n", sum);
        printf("Average: %.2f\n", average);
    } else {
        printf("Invalid input. Please enter non-negative integers.\n");
    }
    return 0;

