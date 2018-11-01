#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP
#define MAXINT std::numeric_limits<int>::max()

#include <algorithm>
#include <limits>
#include <fstream>
#include <vector>

template<typename T>
auto parseStream(std::istream &stream) -> std::vector<T> {
    std::vector<T> v;
    std::istream_iterator<T> input(stream);
    std::copy(input, std::istream_iterator<T>(), std::back_inserter(v));
    return v;
}

auto merge(std::vector<int> &v, const int head, const int mid, const int last) -> void {
    auto sizeLt = mid - head + 1;
    auto sizeRt = last - mid;

    std::vector<int> lt(sizeLt + 1, MAXINT);
    std::vector<int> rt(sizeRt + 1, MAXINT);

    for (auto i = 0; i < sizeLt; i++) {
        lt[i] = v[head + i];
    }

    for (auto i = 0; i < sizeRt; i++) {
        rt[i] = v[mid + 1 + i];
    }

    for (auto i = 0, j = 0, k = head; k <= last; k++) {
        v[k] = lt[i] <= rt[j] ? lt[i++] : rt[j++];
    }
}

auto mergesort(std::vector<int> &v, const int head, const int last) -> void {
    if (head >= last)
        return;

    auto mid = (last + head) / 2;

    mergesort(v, head, mid);
    mergesort(v, mid + 1, last);
    merge(v, head, mid, last);
}

auto mergesort(std::vector<int> &v) -> void {
    mergesort(v, 0, v.size() - 1);
}

auto mergesort(std::istream &input) -> std::vector<int> {
    int n;
    input >> n;
    std::vector<int> v = parseStream<int>(input);
    mergesort(v);
    return v;
}

#endif //MERGE_SORT_HPP
