#include "../libgeometry/intersection.h"
#include "../libgeometry/parser.h"
#include "../libgeometry/perimeter_and_area.h"
#include "../src/libgeometry/lexer.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

int main() {
  std::cout << "\n-------Welcome to program-------\n"
            << "\n----Please, input the shape-----\n"
            << "\n---Example: circle(0 0.0, 1.5)--\n";
  char string1[128] = "circle(10 10.00, 1.5)";
  char string2[128] = "circle(0 0, 2.7)";
  char string3[128] = "circle(10 11, 1.9)";
  bool if_intersect;
  point a[n];

  double rad, x, y;
  cheking_the_input(string1);
  cheking_the_input(string2);
  cheking_the_input(string3);
  for (int j = 0; j < n; j++) {
    input_point(string1, a, 0);
    input_point(string2, a, 1);
    input_point(string3, a, 2);
  }
  for (int j = 0; j < n; j++) {
    printf("circle(%lf %lf, %lf)", a[j].x, a[j].y, a[j].rad);
    printf("\nPerimetr: %.3lf, Area: %.3lf\n", perimeter(a[j].rad),
           area(a[j].rad));
    puts("\n");
    if_intersect = 1;
    for (int i = 0; i < n; i++) {
      if (j != i && intersect(a, i, j) == 1) {
        if (if_intersect) {
          printf(" intersects:");
          if_intersect = 0;
        }
        printf("\n  %d. circle\n", i + 1);
        puts("\n");
      }
    }
  }

  return 0;
}
