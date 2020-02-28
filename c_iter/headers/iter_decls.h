#ifndef C_ITER_ITER_DECLS_H
#define C_ITER_ITER_DECLS_H

#ifndef iter_type
#define iter_type(STL) STL##_iter
#endif

#ifndef iter_begin_decl
#define iter_begin_decl(STL, T) \
  T (*begin)(STL *self)
#endif

#ifndef iter_curr_decl
#define iter_curr_decl(STL, T) \
  T (*current)(STL *self)
#endif

#ifndef iter_end_decl
#define iter_end_decl(STL, T) \
  T (*end)(STL *self)
#endif

#ifndef iter_next_decl
#define iter_next_decl(STL) \
  void (*next)(STL *self)
#endif

#ifndef iter_prev_decl
#define iter_prev_decl(STL) \
  void (*prev)(STL *self)
#endif

#ifndef iter_reset_decl
#define iter_reset_decl(STL) \
  void (*reset)(STL *self)
#endif

#ifndef iterator_field
#define iterator_field(STL) \
  iter_type(STL) *iterator
#endif

#ifndef rev_iterator_field
#define rev_iterator_field(STL) \
  iter_type(STL) *rev_iterator
#endif

#ifndef decl_iterator
#define decl_iterator(STL, T) \
  typedef struct iter_type(STL) iter_type(STL); \
  \
  struct iter_type(STL) { \
    T val; \
    \
    STL *stl; \
    \
    iter_begin_decl(iter_type(STL), T); \
    \
    iter_end_decl(iter_type(STL), T); \
    \
    iter_next_decl(iter_type(STL)); \
    \
    iter_prev_decl(iter_type(STL)); \
    \
    iter_curr_decl(iter_type(STL), T); \
    \
    iter_reset_decl(iter_type(STL)); \
  };
#endif

#ifndef free_iterator
#define free_iterator(stlptr) \
  free(stlptr->iterator)
#endif

#endif // C_ITER_ITER_DECLS_H
