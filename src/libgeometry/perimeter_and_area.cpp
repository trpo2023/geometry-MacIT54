#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctype.h>

#define PI 3.1415926535

void perimeter_and_area(char *s1) {
    int i1, i2;
    double value1, value2, value3, area, perimeter;
    char str_value1[50], str_value2[50], str_value3[50];
    for (int i = 0; i < 30; i++) {
        str_value1[i] = s1[i];
        if ((isdigit(str_value1[i]) == 0) && (str_value1[i] != '.')) {
            str_value1[i] = ' ';
        }
    } 
    for (int i = 7, j = 0; s1[i] != ' '; i++) {
        i1 = i;
        str_value1[j++] = s1[i];
    } 
    value1 = atof(str_value1);
    for (int i = i1 + 2, j = 0; s1[i] != ' '; i++) {
        i2 = i;
        str_value2[j++] = s1[i];
    } 
    value2 = atof(str_value2);
    for (int i = i2 + 2, j = 0; s1[i] != '\0'; i++) {
        str_value3[j++] = s1[i];
    } 
    value3 = atof(str_value3);
    perimeter = 2 * PI * value3;
    area = PI * (value3 * value3);
    std::cout << "perimeter = " << perimeter << "\n";
    std::cout << "area = " << area << "\n\n\n"; 
}
