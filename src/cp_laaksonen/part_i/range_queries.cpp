#include <bits/stdc++.h>

using namespace std;

// Calculate sum of elements in nums vector
// lower index (included)
// upper index (excluded)
int sum(vector<int>& nums, int lower, int upper) {
    int s = 0;
    for (int i = lower; i <= upper; i++) {
        s += nums[i];
    }

    return s;
}

int static_array_sum(vector<int>& nums, int lower, int upper) {
    int c_sum = 0;

    vector<int> prefix_sum;
    prefix_sum.resize(nums.size());

    for (int i = 0; i < nums.size(); i++) {
        c_sum += nums[i];
        prefix_sum[i] = c_sum;
    }

    int l_sum = (lower - 1) < 0 ? 0 : prefix_sum[lower-1];
    int u_sum = prefix_sum[upper];

    return u_sum - l_sum;
}


/*
    Minimum range-query using a sparse table.
*/
vector<int> logarithms;

vector<vector<int>> precompute_sparse_table(vector<int>& nums) {
    int n = nums.size();
    int k = logarithms[n];
    vector<vector<int>> st(nums.size(), vector<int>(k+1));

    // Compute minimum of array [i, i] which is just element at position i
    for (int i = 0; i < n; i++) {
        st[i][0] = nums[i];
    }

    for (int j = 1; j <= k; j++) {
        for (int i = 0; i + (1 << (j)) <= n; i++) {
            st[i][j] = min(st[i][j-1], st[i + (1 << (j-1))][j-1]);
        }
    }

    return st;
}

void compute_logarithms(int n) {
    logarithms.resize(n+1);
    logarithms[1] = 0;
    for (int i = 2; i <= n; i++) {
        logarithms[i] = logarithms[i >> 1] + 1;
    }
}


// Returns the minimum value in the range l (inclusive), r (inclusive)
// using the precomputed sparse table
int range_min_query(vector<vector<int>>& precomputed, int l, int r) {
    int i_length = r - l + 1;
    int i_length_log = logarithms[i_length];

    return min(precomputed[l][i_length_log],
            precomputed[r - (1 << i_length_log) + 1][i_length_log]);
}


int main(int argc, char** argv) {

    /*
    vector<int> v{1,3,8,4,6,1,3,4};

    cout << sum(v,3,6) << "\n";

    v = {1,3,4,8,6,1,4,2};
    cout << static_array_sum(v,3,6) << "\n";
    */

    /*
    vector<int> nums{1,3,4,8,6,1,4,2};
    precompute_sparse_table(nums);
    */

    vector<int> nums{1,3,8,4,6,1,3,4,5,2};

    int n = nums.size();
    compute_logarithms(n);


    auto table = precompute_sparse_table(nums);

    
    int m = range_min_query(table, 2, 3);

    cout << m << "\n";

    return 0;
}