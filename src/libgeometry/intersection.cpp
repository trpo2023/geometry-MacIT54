#include "../src/libgeometry/intersection.h"
#include "../src/libgeometry/perimeter_and_area.h"
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <iostream>

int intersect(point a[], int i, int j) {

  if (j != i) {
    if (sqrt(powf(abs(a[j].x - a[i].x), 2) + powf(abs(a[j].y - a[i].y), 2)) <
        a[j].rad + a[i].rad) {
      return 1;
    }
  }
  return 0;
}