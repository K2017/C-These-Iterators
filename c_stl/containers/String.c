#include "c_stl/containers/headers/String.h"
#include <stdlib.h>
#include <string.h>

override(next, String, void) {
  self->val++;
}

override(prev, String, void) {
  self->val--;
}

override(begin, String, char *) {
  return self->stl->arr;
}

override(end, String, char *) {
  return &(self->stl->arr[self->stl->size - 1]);
}

override(current, String, char *) {
  return self->val;
}

def_iterator(String, char *)

static void stl_free(String *self) {
  free_iterators(self);
  free(self->arr);
  free(self);
}

stl_def_new(String, char *literal) {
  String *str = malloc(sizeof(String));
  unsigned int size = strlen(literal);
  str->size = size;
  str->arr = malloc(sizeof(char) * (size + 1));
  strcpy(str->arr, literal);
  str->free = stl_free;

  make_iterable(String, str);
  make_rev_iterable(String, str);

  return str;
}
