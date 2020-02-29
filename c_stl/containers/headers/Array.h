#ifndef C_ITER_ARRAY_H
#define C_ITER_ARRAY_H

#include "../../STL_util.h"
#include <c_iter/iter.h>

typedef struct Array Array;

decl_iterator(Array, char)

struct Array {
  int size;
  char *arr;

  iterator_field(Array);
  rev_iterator_field(Array);

  void (*free)(Array *self);
};

stl_decl_new(Array, int size);

#endif // C_ITER_ARRAY_H