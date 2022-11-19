#include <bits/stdc++.h>

using namespace std;

// Time complexity: O(n)
int binary_search(int *array, int n, int x) {
    int k = 0;
    for (int b = n / 2; b >= 1; b /= 2) {
        while (k + b < n && array[k + b] <= x) {
            k += b;
        }
    }
    if (array[k] == x) {
        return k;
    }
    return -1;
}

// Find smallest solution that meets criterion
// 

int main(int argc, char **argv) {
    int array[7] = {-19, -3, 4, 42, 76, 918, 1281};
    cout << binary_search(array, 7, 42) << "\n";        // 3

    // Binary search in C++
    auto k = lower_bound(array, array + 7, 42) - array;
    if (k < 7 && array[k] == 42) {
        cout << k << "\n";
    }

    return 0;
}