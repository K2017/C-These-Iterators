cmake_minimum_required(VERSION 3.14)
project(C_These_Iterators C)

set(CMAKE_C_STANDARD 99)

add_library(c_stl
  c_stl/containers/String.c
  c_stl/containers/headers/String.h
  c_stl/containers/Range.c
  c_stl/containers/headers/Range.h
  c_stl/STL.h
  c_stl/STL_util.h
  c_stl/containers/containers.h)

add_library(c_iter
  c_iter/iter.h
  c_iter/forr.h
  c_iter/headers/iter_for.h
  c_iter/headers/iter_decls.h
  c_iter/headers/iter_func.h
  c_iter/headers/iter_defs.h
  )

target_link_libraries(c_stl PRIVATE c_iter)
target_include_directories(c_stl PRIVATE
  "${PROJECT_BINARY_DIR}"
  "${PROJECT_SOURCE_DIR}")

set_target_properties(c_iter PROPERTIES LINKER_LANGUAGE C)
