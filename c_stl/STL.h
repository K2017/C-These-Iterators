#ifndef C_ITER_STL_H
#define C_ITER_STL_H

#include "containers/containers.h"

#ifndef stl_new
#define stl_new(STL, args...) new##STL(args)
#endif

#endif // C_ITER_STL_H
