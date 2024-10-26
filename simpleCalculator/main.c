// C program to illustrate command-line arguments
#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Program name is: %s\n", argv[0]);

    if (argc == 1) {
        printf("No extra command-line arguments passed other than the program name.\n");
    } else {
        printf("Number of arguments passed: %d\n", argc);
        printf("---- Following are the command-line arguments passed ----\n");
        for (int i = 0; i < argc; i++) {
            printf("argv[%d]: %s\n", i, argv[i]);
        }
    }
    return 0;
}
