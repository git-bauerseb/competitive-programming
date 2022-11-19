#include <bits/stdc++.h>

using namespace std;

vector<int> fenwick_tree(vector<int>& nums) {

    vector<int> tree;




    return tree;
}

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


int main() {

    vector<int> nums{1,3,4,8,6,1,4,2};

    FenwickTree tree(nums);

    cout << tree.sum(6) << "\n";

    return 0;
}