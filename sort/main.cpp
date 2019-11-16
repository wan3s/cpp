//
//  main.cpp
//  sort
//
//  Created by Ivan Burimskiy on 15/11/2019.
//  Copyright © 2019 Иван Буримский. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>

#define N 10
#define MIN_ELEM_VALUE -5
#define MAX_ELEM_VALUE 5

using namespace std;

template<typename T>
T get_rand_num (T min, T max) {
    return rand() % (max - min) + min;
}

template<typename T>
auto init_arr(T &arr, int elems_num) {
    for (int i = 0; i < elems_num; ++i){
        arr.push_back(get_rand_num(MIN_ELEM_VALUE, MAX_ELEM_VALUE));
    }
    return arr;
}

template<typename T>
void
print_arr(T *arr, string label = "") {
    if (label.length() > 0) {
        cout << label << ": ";
    }
    for (auto &i : *arr) {
        cout << i << " ";
    }
    cout << endl;
}

template <typename T>
void
my_sort (T left, T right) {
    auto i = left, j = right;
    auto cmp = *i;
    do {
        while (*i < cmp && i < right) {
            ++i;
        }
        while (*j > cmp && j > left) {
            --j;
        }
        if (i <= j) {
            iter_swap(i, j);
            static_cast<void>(++i), --j;
        }
    } while (i <= j);
    if (left < j) {
        my_sort(left, j);
    }
    if (i < right) {
        my_sort(i, right);
    }
}

int main(void) {
    vector<int> my_vec;
    init_arr(my_vec, N);
    vector<int>::iterator begin = my_vec.begin(), end = my_vec.end();
    
    print_arr(&my_vec, "VEC");
    my_sort(begin, end);
    print_arr(&my_vec, "RES");
    
    return 0;
}
