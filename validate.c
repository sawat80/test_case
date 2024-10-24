#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments is provided
    if (argc != 4) {
        printf("Usage: %s <day> <month> <year>\n", argv[0]);
        return 1;
    }

    // Convert arguments to integers
    int day = atoi(argv[1]);
    int month = atoi(argv[2]);
    int year = atoi(argv[3]);

    // Check for valid month
    if (month < 1 || month > 12) {
        printf("Invalid month: %d\n", month);
        return 1;
    }

    // Check for valid day based on the month and leap year
    int isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        // Months with 31 days
        if (day < 1 || day > 31) {
            printf("Invalid day: %d for month: %d\n", day, month);
            return 1;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        // Months with 30 days
        if (day < 1 || day > 30) {
            printf("Invalid day: %d for month: %d\n", day, month);
            return 1;
        }
    } else if (month == 2) {
        // February
        if (isLeapYear) {
            if (day < 1 || day > 29) {
                printf("Invalid day: %d for month: %d\n", day, month);
                return 1;
            }
        } else {
            if (day < 1 || day > 28) {
                printf("Invalid day: %d for month: %d\n", day, month);
                return 1;
            }
        }
    }

    // If all checks passed, the date is valid
    printf("Valid date: %02d/%02d/%d\n", day, month, year);
    return 0;
}

