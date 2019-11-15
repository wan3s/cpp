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

using namespace std;

template <typename T>
auto my_sort(T arr) {
    unsigned int length = arr.size;
    typename T::iterator arr_begin_iter = arr.begin();
    T left_arr, right_arr, sorted_left_arr, sorted_right_arr;
    auto middle_elem_value = *(arr_begin_iter
                               + (length / 2));
    for (auto it = arr_begin_iter; it != arr.end(); ++it) {
        if (*it < middle_elem_value) {
            left_arr.push_back(*it);
        } else {
            right_arr.push_back(*it);
        }
    }
    return 0;
}

int main(void) {

    return 0;
}
