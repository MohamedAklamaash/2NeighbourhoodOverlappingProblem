#ifndef ADJACENCY_HPP
#define ADJACENCY_HPP

#include "interval.hpp"
#include <iostream>

const int MAX_INTERVALS = 100;

void buildAdjList(const Interval intervals[], int n, int adjList[][MAX_INTERVALS], int& edgesCount) {
    edgesCount = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (!(intervals[i].end < intervals[j].start || intervals[j].end < intervals[i].start)) {
                adjList[i][edgesCount] = j;
                adjList[j][edgesCount] = i;
                edgesCount++;
            }
        }
    }
}

void twoNeighbourhoodCover(const Interval intervals[], int n, int adjList[][MAX_INTERVALS], int edgesCount, int coveringSet[], int& setSize) {
    bool covered[MAX_INTERVALS] = {false};
    setSize = 0;

    for (int i = 0; i < n; ++i) {
        if (!covered[i]) {
            coveringSet[setSize++] = intervals[i].id;
            covered[i] = true;

            for (int j = 0; j < edgesCount; ++j) {
                int neighbor = adjList[i][j];
                if (neighbor < MAX_INTERVALS) {
                    covered[neighbor] = true;
                    for (int k = 0; k < edgesCount; ++k) {
                        int secondNeighbor = adjList[neighbor][k];
                        if (secondNeighbor < MAX_INTERVALS) {
                            covered[secondNeighbor] = true;
                        }
                    }
                }
            }
        }
    }
}

#endif
