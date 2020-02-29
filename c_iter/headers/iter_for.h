#ifndef C_ITER_ITER_FOR_H
#define C_ITER_ITER_FOR_H
/*
#ifndef iter_foreach
#define iter_foreach(iterptr, stmts...) \
do { \
  while (iterptr->current(iterptr) != iterptr->end(iterptr)) { \
    stmts \
    iterptr->next(iterptr); \
  } \
  iterptr->reset(iterptr); \
} while(0)
#endif

#ifndef iter_foreach_fwd
#define iter_foreach_fwd(STL, stlptr, stmts...) \
do { \
  iter_type(STL) *iter = stlptr->iterator; \
  iter_foreach(iter, stmts); \
} while(0)
#endif
*/
#ifndef forr_i
#define forr_i(T, var, iterptr, stmts...) \
do { \
  T var = (iterptr)->begin(iterptr); \
  while ((iterptr)->current(iterptr) != (iterptr)->end(iterptr)) { \
    stmts \
    (iterptr)->next(iterptr); \
    var = (iterptr)->current(iterptr); \
  } \
  (iterptr)->reset(iterptr); \
} while(0)
#endif

#ifndef forr
#define forr(T, var, stlptr, stmts...) \
do { \
  T var = (stlptr->iterator)->begin(stlptr->iterator); \
  while ((stlptr->iterator)->current(stlptr->iterator) != (stlptr->iterator)->end(stlptr->iterator)) { \
    stmts \
    (stlptr->iterator)->next(stlptr->iterator); \
    var = (stlptr->iterator)->current(stlptr->iterator); \
  } \
  (stlptr->iterator)->reset(stlptr->iterator); \
} while(0)
#endif

#endif //C_ITER_ITER_FOR_H
