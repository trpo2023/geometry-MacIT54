#include <libgeometry/parser.h>
#include <libgeometry/perimeter_and_area.h>
#include <iostream>
#include <cstring>
#include <ctype.h>
#include <cstdlib>

int main() {
    std::cout << "\n-------Welcome to program-------\n";
    std::cout << "\n----Please, input the shape-----\n";
    char s1[100] = "circle(0 0.0, 1.5)";
    char s2[100] = "circle(0.3 0, 2.57)";
    cheking_the_input(s1);
    perimeter_and_area(s1);
    cheking_the_input(s2);
    perimeter_and_area(s2);
    return 0;
}




