#include "headers/Range.h"
#include <stdlib.h>

void next(iter_type(Range) *self) {
  self->val += 1;
}

void prev(iter_type(Range) *self) {
  self->val -= 1;
}

#define def_iter_begin(Range, int)
int begin(iter_type(Range) *self) {
  return self->stl->lower;
}

#define def_iter_end(Range, int)
int end(iter_type(Range) *self) {
  return self->stl->upper;
}

def_iterator(Range, int)

void freeRange(Range *self) {
  free_iterator(self);
  free(self);
}

stl_def_new(Range, int a, int b) {
  Range *range = malloc(sizeof(Range));
  range->lower = a;
  range->upper = b;
  range->free = freeRange;

  make_iterable(Range, range, &(range->val));
  make_rev_iterable(Range, range, &(range->val));
  return range;
}