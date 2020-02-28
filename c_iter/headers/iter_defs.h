#ifndef C_ITER_ITER_DEFS_H
#define C_ITER_ITER_DEFS_H

#ifndef iter_var
#define iter_var
#endif

#ifndef make_iterable
#define make_iterable(STL, stlptr, varptr) \
  stlptr->iterator = make_iterator(stlptr)
#endif

#ifndef make_rev_iterable
#define make_rev_iterable(STL, stlptr, varptr) \
  stlptr->rev_iterator = make_iterator(stlptr); \
  stlptr->rev_iterator->begin = end; \
  stlptr->rev_iterator->end = begin; \
  stlptr->rev_iterator->next = prev; \
  stlptr->rev_iterator->prev = next; \
  stlptr->rev_iterator->val = end(stlptr->rev_iterator)
#endif

#ifndef def_iter_begin
#define def_iter_begin(STL, T) \
  T begin(iter_type(STL) *self) { \
    return self->stl->lower; \
  }
#endif

#ifndef def_iter_end
#define def_iter_end(STL, T) \
  T end(iter_type(STL) *self) { \
    return self->stl->upper; \
  }
#endif

#ifndef def_iterator
#define def_iterator(STL, T) \
  def_iter_begin(STL, T) \
  \
  T current(iter_type(STL) *self) { \
    return self->val; \
  } \
  \
  def_iter_end(STL, T) \
  \
  void reset(iter_type(STL) *self) { \
    self->val = begin(self); \
  } \
  \
  iter_type(STL) *make_iterator(STL *stl) { \
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
