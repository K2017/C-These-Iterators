#ifndef C_ITER_ARRAY_H
#define C_ITER_ARRAY_H

#include "util.h"
#include <STL.h>

typedef struct Array Array;

decl_iterator(Array, char)

struct Array {
  int idx;
  int size;
  char *arr;

  iterator_field(Array);
};

stl_decl_new(Array, int size);

#endif // C_ITER_ARRAY_H