#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int n = nums.size();

        if (n == 0) {return 0;}
        if (n == 1) {return nums[0] == k ? 1 : 0;}

        int l_ptr = -1;
        int r_ptr = 0;

        int sum = 0;

        int num = 0;

        if (sum == k) {num++;}
        if (r_ptr >= n && sum != k) {return 0;}

        while (l_ptr < n) {
            l_ptr++;

            if (l_ptr > 0) {
                sum -= nums[l_ptr-1];
            }

            while (r_ptr < n && sum + nums[r_ptr] <= k) {
                sum += nums[r_ptr];

                r_ptr++;

            }


            if (sum == k) {
                num++;
                continue;
            }
        }

        return num;
    }
};

int main(int argc, char** argv) {

    Solution solution{};



    vector<vector<int>> testcases{};
    testcases.push_back({0,0,0});
    testcases.push_back({-1,-1,1});

    vector<int> testcases_num{};
    testcases_num.push_back(0);
    testcases_num.push_back(0);

    int i = 0;
    for (auto& case_ : testcases) {
        int matches = solution.subarraySum(case_, testcases_num[i]);
        i++;

        cout << matches << "\n";
    }


    return 0;
}