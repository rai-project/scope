# Adding a New Benchmark

## Overview

1. Add a new benchmark source file
2. Run `../tools/generate_sugar_files.py

## Adding a new Benchmark Source File

This uses [Google's Benchmark support library](github.com/google/benchmark).
The benchmark will need to conform to that pattern.

An example benchmark is in `src/example`.
Briefly, the benchmark should be a function that takes `benchmark::State& state` as an argument, and should be registered with `BENCHMARK(...);`.

A typical benchmark might consist of one or more source files and one or more header files.
Benchmarks are presently grouped into directories representing what they are measuring.

## Run `tools/generate_sugar_files.py`

This generates the `sugar.cmake` files in all of the source directories.
It will add your new benchmark source files to the build system.
It can be run from anywhere, it will only modify the benchmark source directory.