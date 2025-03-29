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

void time_check(int size, float sort_percentage){
    int* tab = new int[size];
    int* tab_heap = new int[size];
    int* tab_tim = new int[size];
    int* tab_intro = new int[size];

    for (int i = 0; i < size; i++) {
        tab[i] = std::rand() % 10000; //filling the table with random values
    }

    if(sort_percentage != 0)
    std::sort(tab, tab + int(sort_percentage*size));

    std::copy(tab, tab + size, tab_heap);
    std::copy(tab, tab + size, tab_tim);
    std::copy(tab, tab + size, tab_intro); //creating an identical table for every sorting algorythm for accurate results

    std::ostringstream filename;
    filename << size << "_" << std::fixed << std::setprecision(3) << sort_percentage << ".csv";

    measure_sorting_timings(tab_heap, size, heapsort, "results/heapsort_" + filename.str());
    measure_sorting_timings(tab_tim, size, timsort, "results/timsort_" + filename.str() );
    measure_sorting_timings(tab_intro, size, introsort, "results/introsort_" + filename.str());

    delete[] tab;
    delete[] tab_heap;
    delete[] tab_tim;
    delete[] tab_intro;
}

int main() {
    const int SIZES[] = {1000, 2000, 5000, 10000, 50000, 100000, 500000, 1000000}; //sizes for the tables
    const float SORT_PERCENTAGE[] = {0, 0.25, 0.50, 0.75, 0.95, 0.99, 0.997, 1}; //percantage of the table that is sorted
    
    for(int size : SIZES){
        for(float sort_percentage : SORT_PERCENTAGE){
            time_check(size, sort_percentage);
        }
    }

    return 0;
}
