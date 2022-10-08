#include <bits/stdc++.h>

using namespace std;

struct P {
    int x, y;
    bool operator<(const P& p) {
        if (x != p.x) {return x < p.x;}
        return y < p.y;
    }
};

// Maximum subarray example
// O(n^3)
int maxSubArraySolution1(int* array, int length) {
    int best = 0;

    for (int a = 0; a < length; a++) {
        for (int b = a; b < length; b++) {
            int sum = 0;
            for (int j = a; j <= b; j++) {sum += array[j];}
            best = max(sum, best);
        }
    }

    return best;
}

// Maximum subarray example
// O(n^2)
int maxSubArraySolution2(int* array, int length) {
    int best = 0;

    for (int a = 0; a < length; a++) {
        int sum = 0;
        for (int b = a; b < length; b++) {
            sum += array[b];
            best = max(best, sum);
        }
    }

    return best;
}

// Maximum subarray example
// O(n^3) [Kadane's algorithm]
int maxSubArraySolution3(int* array, int length) {
    int best = 0;
    int sum = 0;

    for (int a = 0; a < length; a++) {
        sum = max(array[a], array[a] + sum);
        best = max(best, sum);
    }

    return best;
}


template<typename T, typename K>
void apply_vec(vector<T> vec, K lambda) {
    for(auto& e : vec) {lambda(e);}
}

int main() {

    /*
    int array[] = {-1, 2, 4, -3, 5, 2, -11, 2, 9};

    cout << maxSubArraySolution1(array, 9) << "\n";
    cout << maxSubArraySolution2(array, 9) << "\n";
    cout << maxSubArraySolution3(array, 9) << "\n";
    */

    vector<int> v = {4,2,5,3,5,8,3};

    // Sort in increasing order
    sort(v.begin(), v.end());

    // Sort in decreasing order
    sort(v.rbegin(), v.rend());


    vector<tuple<int, int, int>> v_t;
    v_t.push_back({2,1,4});
    v_t.push_back({1,5,3});
    v_t.push_back({2,1,3});

    apply_vec(v_t, [](tuple<int,int,int>& t){
        cout << std::get<0>(t) << "," << std::get<1>(t) << "," << std::get<2>(t) << "\n";});

    
    vector<string,string> v_s;
    v_s.push_back("Hello");
    v_s.push_back("Callback");
    v_s.push_back("Compare");
    v_s.push_back("As");

    // Custom comparator


    return 0;
}