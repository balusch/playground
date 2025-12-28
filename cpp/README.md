# modern-cpp

Small, practical demos for learning modern C++ with a lightweight CMake setup.

## Structure

- `demos/` - step-by-step exercises (by week)
- `topics/` - focused examples by topic
- `tests/` - GoogleTest-based unit tests
- `benchmarks/` - Google Benchmark micro-benchmarks
- `cmake/` - shared CMake helpers

## Build

Using presets:

```sh
cmake --preset debug -S .
cmake --build --preset debug
```

Sanitizers (ASan/UBSan):

```sh
cmake --preset sanitize -S .
cmake --build --preset sanitize
```

## Test

```sh
ctest --preset debug
```

## Benchmarks

```sh
./build/debug/benchmarks/smoke_bench
```

## Notes

- Dependencies are fetched via CMake `FetchContent` when not found locally.
- You can disable fetching with:
  - `-DMODERN_CPP_FETCH_FMT=OFF`
  - `-DMODERN_CPP_FETCH_GTEST=OFF`
  - `-DMODERN_CPP_FETCH_BENCHMARK=OFF`
