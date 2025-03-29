#include <stdlib.h>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <filesystem>

#include "algorythms/heapsort.cpp"
#include "algorythms/insertionsort.cpp"
#include "algorythms/introsort.cpp"
#include "algorythms/quicksort.cpp"
#include "algorythms/timsort.cpp"

#include "algorythms/include/heapsort.hpp"
#include "algorythms/include/insertionsort.hpp"
#include "algorythms/include/introsort.hpp"
#include "algorythms/include/quicksort.hpp"
#include "algorythms/include/timsort.hpp"

#include "timings_test.cpp"
#include "timings_test.hpp"

void time_check(int size){
    int* tab = new int[size];
    int* tab_heap = new int[size];
    int* tab_tim = new int[size];
    int* tab_intro = new int[size];

    for (int i = 0; i < size; i++) {
        tab[i] = std::rand() % 10000; //filling the table with random values
    }

    std::copy(tab, tab + size, tab_heap);
    std::copy(tab, tab + size, tab_tim);
    std::copy(tab, tab + size, tab_intro); //creating an identical table for every sorting algorythm for accurate results

    measure_sorting_timings(tab_heap, size, heapsort, "heapsort_" + std::to_string(size) + ".csv");
    measure_sorting_timings(tab_tim, size, timsort, "timsort_" + std::to_string(size) + ".csv");
    measure_sorting_timings(tab_intro, size, introsort, "introsort_" + std::to_string(size) + ".csv");

    delete[] tab;
    delete[] tab_heap;
    delete[] tab_tim;
    delete[] tab_intro;
}

int main() {
    const int SIZES[] = {1000, 2000, 5000, 10000, 50000, 100000, 500000, 1000000}; //sizes for the tables
    
    for(int size : SIZES){
        time_check(size);
    }

    return 0;
}