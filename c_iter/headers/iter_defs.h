#ifndef C_ITER_ITER_DEFS_H
#define C_ITER_ITER_DEFS_H

#ifndef iter_var
#define iter_var
#endif

#ifndef make_iterable
#define make_iterable(STL, stlptr) \
  stlptr->iterator = make_iterator(stlptr)
#endif

#ifndef make_rev_iterable
#define make_rev_iterable(STL, stlptr) \
  stlptr->rev_iterator = make_iterator(stlptr); \
  stlptr->rev_iterator->begin = end; \
  stlptr->rev_iterator->end = begin; \
  stlptr->rev_iterator->next = prev; \
  stlptr->rev_iterator->prev = next; \
  stlptr->rev_iterator->val = end(stlptr->rev_iterator)
#endif

#ifndef def_iterator
#define def_iterator(STL, T) \
  static void reset(iter_type(STL) *self) { \
    self->val = begin(self); \
  } \
  \
  static iter_type(STL) *make_iterator(STL *stl) { \
    iter_type(STL) *iter = malloc(sizeof(iter_type(STL))); \
    iter->stl = stl; \
    iter->begin = begin; \
    iter->val = iter->begin(iter); \
    iter->end = end; \
    iter->next = next; \
    iter->prev = prev; \
    iter->current = current; \
    iter->reset = reset; \
    return iter; \
  }
#endif

#endif // C_ITER_ITER_DEFS_H
