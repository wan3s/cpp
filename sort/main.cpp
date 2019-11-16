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
#include <string>
#include <array>

#define N 10
#define MIN_ELEM_VALUE -5
#define MAX_ELEM_VALUE 5

using namespace std;

template<typename T>
T
get_rand_num (T min, T max) {
    return rand() % (max - min) + min;
}

template<typename T>
void
init_vec(T &vec, int elems_num) {
    for (int i = 0; i < elems_num; ++i){
        vec.push_back(get_rand_num(MIN_ELEM_VALUE, MAX_ELEM_VALUE));
    }
}

template<typename T>
void
init_arr(T &arr) {
    for (auto iter = arr.begin(); iter != arr.end(); ++iter) {
        *iter = get_rand_num(MIN_ELEM_VALUE, MAX_ELEM_VALUE);
    }
}

template<typename T>
void
print_template(T *arr, string label = "") {
    if (label.length() > 0) {
        cout << label << ": ";
    }
    for (auto iter = (*arr).begin(); iter != (*arr).end(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;
}

template <typename T>
void
my_quick_sort (T left, T right) {
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
        my_quick_sort(left, j);
    }
    if (i < right) {
        my_quick_sort(i, right);
    }
}

int
main(void) {
    vector<int> my_vec;
    array<float, N> my_arr;
    
    init_vec(my_vec, N);
    print_template(&my_vec, "VEC");
    my_quick_sort(my_vec.begin(), my_vec.end());
    print_template(&my_vec, "RES");
    
    init_arr(my_arr);
    print_template(&my_arr, "ARR");
    my_quick_sort(my_arr.begin(), my_arr.end());
    print_template(&my_arr, "RES");
    
    return 0;
}
