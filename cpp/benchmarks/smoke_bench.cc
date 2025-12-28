#include <benchmark/benchmark.h>

#include "view01.h"

static void BM_NoOp(benchmark::State &state) {
  for (auto _ : state) {
    auto msg = make_greeting("bench");
    benchmark::DoNotOptimize(msg);
  }
}

BENCHMARK(BM_NoOp);
