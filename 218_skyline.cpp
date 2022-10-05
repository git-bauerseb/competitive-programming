#include <bits/stdc++.h>

using namespace std;

class FenwickTree {

    public:
        FenwickTree(int n) {
            m_n = n;
            m_bit.assign(n, 0);
        }

        FenwickTree(vector<int> a) : FenwickTree(a.size()) {
            for (size_t i = 0; i < a.size(); i++) {
                add(i, a[i]);
            }
        }

        void add(int idx, int delta) {
            for (; idx < m_n; idx = idx | (idx + 1)) {
                m_bit[idx] += delta;
            }
        }

        int sum(int r) {
            int ret = 0;
            for (; r >= 0; r = (r & (r + 1)) - 1) {
                ret += m_bit[r];
            }

            return ret;
        }

        vector<int> get_representation() {return m_bit;}

    private:
        vector<int> m_bit;
        int m_n;

};


#define LEFT 0
#define RIGHT 1
#define HEIGHT 2

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int num_buildings = buildings.size();
        
      
        stack<vector<int>> active_buildings;

        int currentX = buildings[0][LEFT];
        int currentY = buildings[0][HEIGHT];

        for (auto& b : buildings) {
            if (b[LEFT] <= currentX && currentX <= b[RIGHT]) {
                active_buildings.push(b);
            }
        }

        for (int i = 0; i < active_buildings.size(); i++) {
            currentY = max(currentY, );
        }




        return result;
    }
};


int main() {

    vector<vector<int>> buildings;
    buildings.push_back({2,9,10});
    buildings.push_back({3,7,15});
    buildings.push_back({5,12,12});

    Solution solution{};
    solution.getSkyline(buildings);


    return 0;
}