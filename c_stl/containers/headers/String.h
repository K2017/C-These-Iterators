#ifndef CTI_STRING_H
#define CTI_STRING_H

#include "../../STL_util.h"
#include <c_iter/iter.h>

typedef struct String String;

decl_iterator(String, char *)

struct String {
  unsigned int size;
  char *arr;

  iterator_field(String);
  rev_iterator_field(String);

  void (*free)(String *self);
};

stl_decl_new(String, char *literal);

#endif // CTI_STRING_H