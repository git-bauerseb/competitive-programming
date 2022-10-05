#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
    public:
        SegmentTree(vector<int> nums) {
            m_n = nums.size();
            m_tree.resize(2*m_n);

            for (int i = 0; i < m_n; i++) {
                add(i, nums[i]);
            }
        }


        // Add element to segment tree.
        // Time complexity: O(log(n)) where n is the number of
        //                  elements in the array
        void add(int index, int element) {
            index += m_n;
            m_tree[index] += element;

            for (index /= 2; index > 0; index /= 2) {
                m_tree[index] = m_tree[2 * index] + m_tree[2*index + 1];
            }
        }

        // Compute the range sum in the range [a,b] (both inclusive)
        // Time complexity: O(log(n)) where n is the number of elements in the array
        int sum(int a, int b) {
            a += m_n;
            b += m_n;
            int sum = 0;

            while (a <= b) {
                if (a % 2 == 1) {
                    sum += m_tree[a++];
                }

                if (b % 2 == 0) {
                    sum += m_tree[b--];
                }

                a /= 2;
                b /= 2;
            }

            return sum; 
        }

        friend ostream& operator<<(ostream& os, const SegmentTree& tree);

    private:
        int m_n;
        vector<int> m_tree;
};

ostream& operator<<(ostream& os, const SegmentTree& tree) {
    for (auto& e : tree.m_tree) {
        os << e << " ";
    }

    os << "\n";
    return os;
}

int main() {
    SegmentTree tree({5,8,6,3,2,7,2,6});
    cout << tree.sum(2, 7) << "\n";
    cout << tree;
    

    return 0;
}