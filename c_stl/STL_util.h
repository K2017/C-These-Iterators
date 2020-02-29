#ifndef C_ITER_UTIL_H
#define C_ITER_UTIL_H

#ifndef stl_decl_new
#define stl_decl_new(STL, args...) \
  STL *new##STL(args)
#endif

#ifndef stl_def_new
#define stl_def_new(STL, args...) \
  STL *new##STL(args)
#endif

#endif // C_ITER_UTIL_H
