#ifndef C_ITER_RANGE_H
#define C_ITER_RANGE_H

#include "util.h"
#include <iter.h>

typedef struct Range Range;

decl_iterator(Range, int)

struct Range {
  int lower, upper;

  iterator_field(Range);
  rev_iterator_field(Range);

  void (*free)(Range *self);
};

stl_decl_new(Range, int a, int b);

#endif // C_ITER_RANGE_H
