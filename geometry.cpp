#include <iostream>
#include <cstring>
#include <ctype.h>

using namespace std;

int main() {
    char s[100] = "circle(0 0.5, 1.23)";
    char circle[7] = "circle";
    int i, i1, i2;
    for (i = 0; i < 7; i++) { // Checking the shape type and the first bracket
        if (s[i] != circle[i] && i < 6) {
            printf("\nInvalid syntax, error at column %d: expected: 'circle'\n", i + 1);
            printf("Your input: %s\n\n", s);
            exit(0);
        }
        i1 = i;
        if (s[i] != '(' && i == 6) {
            printf("\nInvalid syntax, error at column %d: expected: '('\n", i + 1);
            printf("Your input: %s\n\n", s);
            exit(0);
        }
    } 
    if (s[int(strlen(s)) - 1] != ')') { // Cheking the second bracket
        printf("\nInvalid syntax, error at column %d: expected: ')'\n", i + 1);
        printf("Your input: %s\n\n", s);
        exit(0);
    }
    for (i = i1 + 1; s[i] != ','; i++) { // Cheking numbers
        if (isdigit(s[i]) == 0 && s[i] != '.' && s[i] != ' ' && s[i] != ',') {
            printf("\nInvalid syntax, error at column %d: expected: '<double>'\n", i + 1);
            printf("Your input: %s\n\n", s);
            exit(0);
        }
        i2 = i;
    }
    for (i = i2 + 2; i < int(strlen(s)) - 1; i++) { // Cheking numbers
        if (isdigit(s[i]) == 0 && s[i] != '.' && s[i] != ' ') {
            printf("\nInvalid syntax, error at column %d: expected: '<double>'\n", i + 1);
            printf("Your input: %s\n\n", s);
            exit(0);
        }
    }
    printf("\nReady input: %s\n", s);
    printf("There are no errors, code 0\n\n");
    return 0;
}
