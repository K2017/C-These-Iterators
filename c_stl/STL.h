#ifndef CTI_STL_H
#define CTI_STL_H

#include "containers/containers.h"

#ifndef stl_new
#define stl_new(STL, args...) \
  new##STL(args)
#endif

#endif // CTI_STL_H