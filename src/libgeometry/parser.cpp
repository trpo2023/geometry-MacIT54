#include <libgeometry/parser.h>
#include <libgeometry/perimeter_and_area.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctype.h>

void check_symbols(char *s, int i) {
    if ((isdigit(s[i]) == 0 && s[i] != '.' && s[i] != ' ' && s[i] != ',') 
        || ((s[i] == '.' && s[i + 1] == '.') || (s[i] == '.' && s[i - 1] == '.')) 
        || (isdigit(s[i]) == 0 && s[i - 1] == '.' && s[i + 1 == '.'])
        || (s[i] == '.' && (s[i - 1] == ' ' || s[i + 1] == ' '))
        || (s[i] == '.' && (s[i - 1] == ',' || s[i + 1] == ','))
        || (s[i] == '.' && (isdigit(s[i - 1]) == 0 || isdigit(s[i + 1]) == 0))) {
            printf("\nInvalid syntax, error at column %d: expected: '<double>'\n", i + 1);
            printf("Your input: %s\n\n", s);
        }
}

void cheking_the_input(char *s) {
    char circle[7] = "circle";
    int i, i1, i2, i4, k1 = 0, k2 = 0, k3 = 0, k4 = 0;
    for (int i3 = 0; i3 < 100; i3++) {
        if (s[i3] == ',') {
            k3 += 1;
            if (k3 != 1) {
                printf("\nInvalid syntax, error at column %d: expected: ','\n", i3 + 1);
                printf("Your input: %s\n\n", s);
                exit(0);
            }
        }
    }
    for (i = 0; i < 7; i++) { // Checking the shape type and the first bracket
        if (s[i] != circle[i] && i < 6) {
            printf("\nInvalid syntax, error at column %d: expected: 'circle'\n", i + 1);
            printf("Your input: %s\n\n", s);
        }
        i1 = i;
        if (s[i] != '(' && i == 6) {
            printf("\nInvalid syntax, error at column %d: expected: '('\n", i + 1);
            printf("Your input: %s\n\n", s);
        }
    } 
    if (s[int(strlen(s)) - 1] != ')') { // Cheking the second bracket
        printf("\nInvalid syntax, error at column %d: expected: ')'\n", i + 1);
        printf("Your input: %s\n\n", s);
    }
    for (i = i1; s[i] != ' '; i++) { // Cheking numbers
        i4 = i;
        if (s[i] == '.') {
            k4 += 1;
            if (k4 > 1) {
                printf("\nInvalid syntax, error at column %d: expected: '<double>'\n", i + 1);
                printf("Your input: %s\n\n", s);
            }
        }
    }
    for (i = i4 + 1; s[i] != ','; i++) { // Cheking numbers
        check_symbols(s, i);
        i2 = i;
        if (s[i] == '.') {
            k1 += 1;
            if (k1 > 1) {
                printf("\nInvalid syntax, error at column %d: expected: '<double>'\n", i + 1);
                printf("Your input: %s\n\n", s);
            }
        }
    }
    for (i = i2 + 2; i < int(strlen(s)) - 1; i++) { // Cheking numbers
        check_symbols(s, i);
        if (s[i] == '.') {
            k2 += 1;
            if (k2 > 1) {
                printf("\nInvalid syntax, error at column %d: expected: '<double>'\n", i + 1);
                printf("Your input: %s\n\n", s);
            }
        }
    }
    printf("\n%s\n", s);
}