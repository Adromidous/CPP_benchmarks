#include <iostream>
#include "binary_search.h"
#include <benchmark/benchmark.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

static void BENCHMARK_bin (benchmark::State &state) {

	int* arr = new int[SIZE];
	srand(time(0));

	for (int i = 0; i < SIZE; i++) {
		arr[i] = i;
	}		

	int* temp = arr;

	for (auto _ : state) {
		
		int val = rand() % SIZE;	
		benchmark::DoNotOptimize(branchless_binary_search(arr, val, SIZE));
		arr = temp;
	}

	delete [] arr;
	temp = nullptr;
}

BENCHMARK(BENCHMARK_bin);

BENCHMARK_MAIN();
