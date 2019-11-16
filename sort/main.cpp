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
void my_sort (typename T::iterator left, typename T::iterator right) {
    typename T::iterator i = left, j = right;
    auto cmp = *((left + right) / 2);
    do {
        while (*i < cmp && i < right) {
            ++i;
        }
        while (*j > cmp && j > left) {
            --j;
        }
        if (i <= j) {
            auto tmp = *i;
            *i = *j;
            *j = tmp;
            ++i, --j;
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

    return 0;
}
