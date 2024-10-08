#include <iostream>
#include "heapsort.hpp"
#include "adjacency.hpp"


int main() {
    Interval intervals[MAX_INTERVALS] = {
        {0, 3, 1}, {1, 4, 2}, {2, 7, 3}, {3, 9, 6}, {4, 10, 8}
    };
    
    int n = 5;
    
    if (n > MAX_INTERVALS) {
        std::cerr << "Error: Too many intervals! Maximum allowed is " << MAX_INTERVALS << std::endl;
        return 1;
    }

    HeapSort heapSort;
    heapSort.heapSort(intervals, n);

    int adjList[MAX_INTERVALS][MAX_INTERVALS] = {0};
    int edgesCount;

    buildAdjList(intervals, n, adjList, edgesCount);
    
    if (edgesCount >= MAX_INTERVALS) {
        std::cerr << "Error: Edge count exceeds maximum!" << std::endl;
        return 1;
    }

    int coveringSet[MAX_INTERVALS] = {0};
    int setSize;
    twoNeighbourhoodCover(intervals, n, adjList, edgesCount, coveringSet, setSize);

    std::cout << "The minimal 2-neighbourhood covering set is: ";
    for (int i = 0; i < setSize; ++i) {
        std::cout << coveringSet[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
