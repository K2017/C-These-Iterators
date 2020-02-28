cmake_minimum_required(VERSION 3.14)
project(C_Iterators C)
include_directories(c_iter c_stl)

set(CMAKE_C_STANDARD 99)

add_library(c_stl
  c_stl/containers/Array.c
  c_stl/containers/headers/Array.h
  c_stl/containers/Range.c
  c_stl/containers/headers/Range.h
  c_stl/STL.h
  c_stl/util.h
  c_stl/containers/containers.h)

add_library(c_iter
  SHARED
  c_iter/iter.h
  c_iter/forr.h
  c_iter/headers/iter_for.h
  c_iter/headers/iter_decls.h
  c_iter/headers/iter_func.h
  c_iter/headers/iter_defs.h
  )

add_executable(c_iter_test
  src/main.c
  c_iter/iter.h
  c_stl/containers/headers/Range.h
  c_stl/containers/Range.c
  c_stl/STL.h
  c_stl/containers/Array.c
  c_stl/containers/headers/Array.h)

set_target_properties(c_iter PROPERTIES LINKER_LANGUAGE C)