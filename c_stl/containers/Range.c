#include "headers/Range.h"
#include <stdlib.h>

static void next(iter_type(Range) *self) {
  self->val += 1;
}

static void prev(iter_type(Range) *self) {
  self->val -= 1;
}

static int begin(iter_type(Range) *self) {
  return self->stl->lower;
}

static int end(iter_type(Range) *self) {
  return self->stl->upper;
}

static int current(iter_type(Range) *self) {
  return self->val;
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

  make_iterable(Range, range);
  make_rev_iterable(Range, range);
  return range;
}