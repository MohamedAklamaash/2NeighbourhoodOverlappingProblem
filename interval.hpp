#ifndef INTERVAL_HPP
#define INTERVAL_HPP

struct Interval {
    int id, end, start;

    Interval(int id_ = 0, int end_ = 0, int start_ = 0) : id(id_), end(end_), start(start_) {}
};

#endif
