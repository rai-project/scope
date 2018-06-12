# This file generated automatically by:
#   generate_sugar_files.py
# see wiki for more info:
#   https://github.com/ruslo/sugar/wiki/Collecting-sources

if(DEFINED SRC_NUMA_SUGAR_CMAKE_)
  return()
else()
  set(SRC_NUMA_SUGAR_CMAKE_ 1)
endif()

include(sugar_files)

sugar_files(
    BENCHMARK_HEADERS
    args.hpp
    ops.hpp
)

sugar_files(
    BENCHMARK_SOURCES
    wr.cpp
    rd.cpp
    ops.cpp
)

