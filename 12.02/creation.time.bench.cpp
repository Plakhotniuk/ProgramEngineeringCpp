#include <string>
#include <string_view>

#include <benchmark/benchmark.h>

///////////////////////////////////////////////////////////////////

void test_v1(benchmark::State & state)
{

    for (auto _ : state)
    {
        std::string string(22, 'a');
        benchmark::DoNotOptimize(string);
    }

    state.SetComplexityN(state.range(0));
}

///////////////////////////////////////////////////////////////////

void test_v2(benchmark::State & state)
{

    for (auto _ : state)
    {
        std::string string(23, 'a');
        benchmark::DoNotOptimize(string);
    }

    state.SetComplexityN(state.range(0));
}

///////////////////////////////////////////////////////////////////

BENCHMARK(test_v1)->DenseRange(1, 10'000, 1'000)->Complexity();

BENCHMARK(test_v2)->DenseRange(1, 10'000, 1'000)->Complexity();

///////////////////////////////////////////////////////////////////

int main()
{
    benchmark::RunSpecifiedBenchmarks();
}

// Результаты сравнения: 

// -------------------------------------------------------
// Benchmark             Time             CPU   Iterations
// -------------------------------------------------------
// test_v1/1          48.1 ns         47.9 ns     14601555
// test_v1/1001       49.7 ns         48.0 ns     14560916
// test_v1/2001       47.9 ns         47.8 ns     14631618
// test_v1/3001       48.1 ns         48.0 ns     14568067
// test_v1/4001       48.1 ns         48.0 ns     14531112
// test_v1/5001       48.3 ns         48.1 ns     14579111
// test_v1/6001       48.1 ns         48.0 ns     14586038
// test_v1/7001       48.3 ns         48.1 ns     14635625
// test_v1/8001       48.2 ns         48.0 ns     14581116
// test_v1/9001       48.1 ns         48.0 ns     14584093
// test_v1_BigO      48.30 (1)       48.00 (1)  
// test_v1_RMS           1 %             0 %    
// test_v2/1          99.6 ns         99.3 ns      7018388
// test_v2/1001       99.8 ns         99.5 ns      7038996
// test_v2/2001       99.8 ns         99.6 ns      7075496
// test_v2/3001       99.5 ns         99.2 ns      6991540
// test_v2/4001       99.3 ns         99.1 ns      7041899
// test_v2/5001        100 ns          100 ns      7134558
// test_v2/6001       99.7 ns         99.5 ns      7044096
// test_v2/7001        100 ns          100 ns      7049771
// test_v2/8001        100 ns         99.9 ns      6983589
// test_v2/9001        101 ns          100 ns      6830801
// test_v2_BigO     100.03 (1)       99.66 (1)  
// test_v2_RMS           1 %             0 %   

// Итог: строка размера N+1 создается почти в 2 раза дольше, чем размера N.