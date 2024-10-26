#include <stdio.h>
#include <stdlib.h>

// Function to validate the date
int isValidDate(int day, int month, int year) {
    // Check for valid month
    if (month < 1 || month > 12) {
        return 0; // Invalid month
    }

    // Days in each month
    int daysInMonth;
    if (month == 2) {
        // Check for leap year
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            daysInMonth = 29; // Leap year
        } else {
            daysInMonth = 28; // Non-leap year
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        daysInMonth = 30; // April, June, September, November
    } else {
        daysInMonth = 31; // Other months
    }

    // Check for valid day
    if (day < 1 || day > daysInMonth) {
        return 0; // Invalid day
    }

    return 1; // Valid date
}

// Function to calculate the next day
int calculateNextDay(int *day, int *month, int *year) {
    // Validate the current date before calculating the next day
    if (!isValidDate(*day, *month, *year)) {
        return 0; // Return 0 if the date is invalid
    }

    (*day)++; // Move to the next day

    // Check if we need to rollover to the next month
    int daysInMonth;
    if (*month == 2) {
        // Check for leap year
        if ((*year % 4 == 0 && *year % 100 != 0) || (*year % 400 == 0)) {
            daysInMonth = 29; // Leap year
        } else {
            daysInMonth = 28; // Non-leap year
        }
    } else if (*month == 4 || *month == 6 || *month == 9 || *month == 11) {
        daysInMonth = 30; // April, June, September, November
    } else {
        daysInMonth = 31; // Other months
    }

    if (*day > daysInMonth) {
        *day = 1;        // Reset day to 1
        (*month)++;      // Move to the next month
        if (*month > 12) {
            *month = 1; // Reset month to January
            (*year)++;   // Increment year
        }
    }

    return 1; // Return 1 if the next day is calculated successfully
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <day> <month> <year>\n", argv[0]);
        return 1; // Exit if the number of arguments is incorrect
    }

    // Convert command line arguments to integers
    int day = atoi(argv[1]);
    int month = atoi(argv[2]);
    int year = atoi(argv[3]);

    // Calculate the next day and validate the date
    if (calculateNextDay(&day, &month, &year)==0) {
        printf("Invalid date entered.\n");
        return 0; // Exit if date is invalid
    }

    // Display the next day
    printf("The day after is: %02d/%02d/%d\n", day, month, year);

    return 0;
}
