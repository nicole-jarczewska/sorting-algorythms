#include <iostream>
#include <algorithm>
#include <cmath>

#include "include/insertionsort.hpp"
#include "include/heapsort.hpp"
#include "include/quicksort.hpp"
#include "include/introsort.hpp"

// Introsort helper function
void introsortUtil(int* tab, int start, int end, int depthLimit) {
    int size = end - start + 1;
    if (size < 16) {
        insertionsort(tab, start, end);
        return;
    }
    if (depthLimit == 0) {
        heapsort(tab + start, size);
        return;
    }
    quicksort(tab, start, end);
}

// Introsort function
void introsort(int* tab, int size) {
    int depthLimit = 2 * log(size);
    introsortUtil(tab, 0, size - 1, depthLimit);
}