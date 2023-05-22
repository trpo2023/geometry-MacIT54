#include "../src/libgeometry/lexer.h"
#include "../src/libgeometry/intersection.h"
#include "../src/libgeometry/perimeter_and_area.h"
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <iostream>

void input_point(char *s1, point a[], int j) {
  int i1, i2;
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
  a[j].x = atof(str_value1);
  for (int i = i1 + 2, j = 0; s1[i] != ' '; i++) {
    i2 = i;
    str_value2[j++] = s1[i];
  }
  a[j].y = atof(str_value2);
  for (int i = i2 + 2, j = 0; s1[i] != '\0'; i++) {
    str_value3[j++] = s1[i];
  }
  a[j].rad = atof(str_value3);

  str_value1[50] = {};
  str_value2[50] = {};
  str_value3[50] = {};

  // sscanf(string1, "circle(%lf %lf, %lf)", &a[0].x, &a[0].y, &a[0].rad);
  // sscanf(string2, "circle(%lf %lf, %lf)", &a[1].x, &a[1].y, &a[1].rad);
  // sscanf(string3, "circle(%lf %lf, %lf)", &a[2].x, &a[2].y, &a[2].rad);
  //  sscanf(string, "circle(%lf %lf, %lf)", &x, &y, &rad)
}