    #include <stdio.h>
// Procedure to calculate sum and average
void calculateSumAndAverage(int num1, int num2, int *sum, float *average) {
    *sum = num1 + num2;                 // Calculate sum
    *average = *sum / 2.0;              // Calculate average
}
int main() {
    int number1, number2;
    int sum;
    float average;

    // Input two integers
    printf("Enter two integers: ");
    scanf("%d %d", &number1, &number2);

    // Call the function
    calculateSumAndAverage(number1, number2, &sum, &average);

    // Print the results
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);

    return 0;
}
