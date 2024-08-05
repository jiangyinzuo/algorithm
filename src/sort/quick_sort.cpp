//
// Created by Jiang Yinzuo on 2020/3/18.
//

#include <iostream>
#include <algorithm>

template<typename Iter>
Iter partition(Iter first, Iter last) {
    Iter i = first + 1;
    Iter j = last - 1;
    Iter pivot = first;
    while (i <= j) {
        while (i <= j && *i < *pivot) ++i;
        while (i <= j && *j > *pivot) --j;
        if (i <= j) std::swap(*i++, *j--);
    }
    std::swap(*pivot, *j);
    return j;
}

template<typename Iter>
void quick_sort(Iter first, Iter last) {
    if (first >= last - 1) return;
    Iter pivot = partition(first, last);
    quick_sort(first, pivot);
    quick_sort(pivot + 1, last);
}

int main() {
    int a[10] {2, 2, 3, 2, 5, 5, 4, 4, 5, 5};
    quick_sort(a, a + 10);

    for (auto &i : a) std::cout << i << " ";
    return 0;
}