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

//template <typename T>
void my_sort (vector<int>::iterator &left, vector<int>::iterator &right) {
    vector<int>::iterator i = left, j = right;
    auto cmp = *i;
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
            ++i;
            --j;
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
    vector<int> my_vec = {5, 4, 3, 2, 1};
    vector<int>::iterator begin = my_vec.begin(), end = my_vec.end();
    my_sort(begin, end);
    for (auto &i : my_vec) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
