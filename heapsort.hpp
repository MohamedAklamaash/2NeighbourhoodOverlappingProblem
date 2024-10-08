#ifndef HEAP_SORT_HPP
#define HEAP_SORT_HPP

#include "interval.hpp"

class HeapSort {
public:
    void heapify(Interval intervals[], int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && intervals[left].start > intervals[largest].start)
            largest = left;

        if (right < n && intervals[right].start > intervals[largest].start)
            largest = right;

        if (largest != i) {
            std::swap(intervals[i], intervals[largest]);
            heapify(intervals, n, largest);
        }
    }

    void heapSort(Interval intervals[], int n) {
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(intervals, n, i);

        for (int i = n - 1; i > 0; i--) {
            std::swap(intervals[0], intervals[i]);
            heapify(intervals, i, 0);
        }
    }
};

#endif