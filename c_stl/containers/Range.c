#include "headers/Range.h"
#include <stdlib.h>

override(next, Range, void) {
  self->val += 1;
}

override(prev, Range, void) {
  self->val -= 1;
}

override(begin, Range, int) {
  return self->stl->lower;
}

override(end, Range, int) {
  return self->stl->upper;
}

override(current, Range, int) {
  return self->val;
}

def_iterator(Range, int)

static void stl_free(Range *self) {
  free_iterators(self);
  free(self);
}

stl_def_new(Range, int a, int b) {
  Range *range = malloc(sizeof(Range));
  range->lower = a;
  range->upper = b;
  range->free = stl_free;

  make_iterable(Range, range);
  make_rev_iterable(Range, range);
  return range;
}