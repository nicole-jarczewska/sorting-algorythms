#include <iostream>

#include "include/heapsort.hpp"

void make_heap(int* tab, int current_size, int i) {
    int largest = i; //largest element
    int left = 2 * i + 1; // index of left node 
    int right = 2 * i + 2; // index of right node

    if (left < current_size && tab[left] > tab[largest])
        largest = left;

    if (right < current_size && tab[right] > tab[largest])
        largest = right;

    // If parent is not larger than children, swap
    if (largest != i) {
        std::swap(tab[i], tab[largest]);

        make_heap(tab, current_size, largest);
    }
}

void heapsort(int* tab, int size) {

    for (int i = size / 2 - 1; i >= 0; i--)
        make_heap(tab, size, i);

    // Extract elements from heap one by one
    for (int i = size - 1; i > 0; i--) {
        // Move current root to end
        std::swap(tab[0], tab[i]);

        // Call max heapify on the reduced heap
        make_heap(tab, i, 0);
    }
}

