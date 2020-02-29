#include "headers/Array.h"
#include <stdlib.h>

static void next(iter_type(Array) *self) {
  self->val += 1;
}

static void prev(iter_type(Array) *self) {
  self->val -= 1;
}

static char begin(iter_type(Array) *self) {
  return self->stl->arr[0];
}

static char end(iter_type(Array) *self) {
  return self->stl->arr[self->stl->size - 1];
}

static char current(iter_type(Array) *self) {
  return self->stl->arr[self->val];
}

def_iterator(Array, char)

void freeArray(Array *self) {
  free_iterator(self);
  free(self->arr);
  free(self);
}

stl_def_new(Array, int size) {
  Array *array = malloc(sizeof(Array));
  array->size = size;
  array->arr = malloc(sizeof(char) * size);
  array->free = freeArray;

  make_iterable(Array, array);
  make_rev_iterable(Array, array);

  return array;
}
