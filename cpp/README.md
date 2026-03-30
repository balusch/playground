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

Offline or system-packages-only:

```sh
cmake -S . -B build/offline \
  -DMODERN_CPP_FETCH_FMT=OFF \
  -DMODERN_CPP_FETCH_GTEST=OFF \
  -DMODERN_CPP_FETCH_BENCHMARK=OFF
cmake --build build/offline
```

## Test

```sh
ctest --preset debug
```

## Benchmarks

```sh
./build/debug/benchmarks/smoke_bench
```

## Neovim

Quick path:

1. Enable local project config in your `init.lua`:

```lua
vim.o.exrc = true
vim.o.secure = true
```

2. Configure the project once so `clangd` can read compile commands:

```sh
cmake --preset debug -S .
```

3. Open the repo in Neovim. This project now includes:

- `.clangd`
  Points `clangd` at `build/debug/compile_commands.json`
- `.nvim.lua`
  Adds project-local indentation and repo-specific task mappings
- `.tasks.ini`
  Overrides the generic C/C++ AsyncTasks with this repo's CMake preset flow

This integrates with your global AsyncTask setup in `dotfiles`:

- global `<Leader>ab` / `<Leader>aB`
  Build debug / release using this repo's local `c-*` tasks
- global `<Leader>ar` / `<Leader>aR`
  Run the current target in debug / release
- global `<Leader>at`
  Run tests for the current target or the debug preset
- global `<Leader>ap`
  Profile-style release run of the current target

Additional repo-local shortcuts:

- `<Leader>rc`
  Configure the debug preset
- `<Leader>rb`
  Build the current target
- `<Leader>rr`
  Run the current target
- `<Leader>rt`
  Test the current target

Local commands:

- `:CppConfigure`
- `:CppBuild`
- `:CppRun`
- `:CppTest`

Recommended tooling:

- `clangd`
- a basic LSP client such as `nvim-lspconfig`
- Treesitter for C and C++

## Notes

- Dependencies are fetched via CMake `FetchContent` when not found locally.
- You can disable fetching with:
  - `-DMODERN_CPP_FETCH_FMT=OFF`
  - `-DMODERN_CPP_FETCH_GTEST=OFF`
  - `-DMODERN_CPP_FETCH_BENCHMARK=OFF`
- The current local toolchain supports useful C++23 library features, but it is
  not a practical setup for standard C++26 reflection experiments.

## Learning Roadmap

For this repo, the most practical way to learn modern C++ is:

1. build strong C++17 fundamentals
2. learn the core C++20 model
3. add the highest-value C++23 library features
4. treat C++26 as a watchlist, not the main path

The key point is that C++17 and C++20 carry most of the conceptual weight.
C++23 is mostly a set of useful refinements. C++26 is still too incomplete
across toolchains to use as a main learning target.

### C++17

This is the foundation for writing modern C++ comfortably.

- `std::string_view`
  Very useful, but learn lifetime rules early.
- `std::optional`
  Expresses "maybe a value" clearly.
- `std::variant` and `std::visit`
  Good for modeling explicit state without unsafe unions.
- structured bindings
  Common and immediately useful.
- `if constexpr`
  One of the most important tools for template code.
- fold expressions
  Worth learning once variadic templates start to appear.
- inline variables
  Small feature, but helps clean up header-only constants.
- `std::filesystem`
  High practical value for small tools and utilities.

### C++20

This is the most important modern C++ layer after C++17 basics.

- concepts
  Improves template constraints and compiler diagnostics.
- ranges and `std::views`
  Core modern style for data transformation pipelines.
- `std::span`
  Excellent for non-owning contiguous views in APIs.
- `<=>`
  Learn defaulted comparisons and ordering semantics.
- `consteval` and `constinit`
  Useful for understanding compile-time boundaries.
- `std::jthread` and `std::stop_token`
  Better default threading tools than older patterns.
- `std::source_location`
  Very handy for logging and diagnostics.

Second phase topics:

- coroutines
  Important, but noticeably harder than the rest.
- modules
  Useful to understand, but toolchain and build-system support still matters.

### C++23

This is a good layer for practical upgrades once C++17/20 are comfortable.

- `std::expected`
  Explicit success-or-error return values.
- `std::print` and `std::println`
  Simple modern output APIs.
- `std::move_only_function`
  Useful when callables own move-only state.
- deducing `this`
  Good for more expressive generic member functions.
- `if consteval`
  Cleaner compile-time vs runtime branching.
- smaller library improvements
  Includes helpers such as `starts_with`, `ends_with`, `contains`,
  `to_underlying`, and `byteswap`.

Lower priority:

- `mdspan`
- `stacktrace`
- `flat_map` / `flat_set`

### C++26

As of 2026-03-30, C++26 is better treated as "follow and sample" rather than
"study deeply first".

- contracts
  Worth tracking conceptually.
- reflection
  High long-term value, but not ready as a main learning target on this local
  toolchain.
- `inplace_vector`
  Interesting and practical, but not foundational.
- hazard pointers / RCU / SIMD / linalg
  Domain-specific topics, best learned when the project needs them.

## Suggested Order

A pragmatic cross-version order for this repo is:

1. C++17: `std::string_view`
2. C++17: `std::optional`
3. C++17: `std::variant` and `std::visit`
4. C++17: structured bindings
5. C++17: `if constexpr`
6. C++20: `std::span`
7. C++20: concepts
8. C++20: ranges with `std::views`
9. C++20: `<=>`
10. C++20: `consteval` and `constinit`
11. C++20: `std::jthread` and `std::stop_token`
12. C++20: `std::source_location`
13. C++23: `std::expected`
14. C++23: `std::print` / `std::println`
15. C++23: `std::move_only_function`
16. C++23: deducing `this`
17. C++23: `if consteval`
18. C++26: contracts and reflection tracking only

See `topics/` for small runnable examples. Add new topics in roughly this
order.
