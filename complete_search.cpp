#include <bits/stdc++.h>

using namespace std;

// Subsets
// Method 1: Recursion
void subset1(vector<int>& subset, int k, int n) {
    if (k == n) {
        for (auto& e : subset) {cout << e << " ";}
        cout << "\n";
    } else {
        subset1(subset, k+1, n);
        subset.push_back(k);
        subset1(subset, k+1, n);
        subset.pop_back();
    }
}

// Method 2: Bit representation 
void subset2(vector<int>& subset, int n) {
    for (int b = 0; b < (1 << n); b++) {
        for (int i = 0; i < n; i++) {
            if (b & (1 << i)) {subset.push_back(i);}
        }

        for (auto& e : subset) {cout << e << " ";}
        cout << "\n";

        subset.clear();
    }
}

// Permutations
// Method 1: Recursion
void permutation1(vector<int>& perm, vector<bool>& chosen, size_t n) {
    if (perm.size() == n) {
        for (auto& e : perm) {cout << e << " ";}
        cout << "\n";
    } else {
        for (size_t i = 0; i < n; i++) {
            if (chosen[i]) {continue;}
            chosen[i] = true;
            perm.push_back(i);
            permutation1(perm, chosen, n);
            chosen[i] = false;
            perm.pop_back();
        }
    }
}

// Method 2: Iteration
void permutation2(vector<int>& v, int n) {
    for (int i = 0; i < n; i++) {
        v.push_back(i);
    }

    do {
        for (auto& e : v) {cout << e << " ";}
        cout << "\n";
    } while (next_permutation(v.begin(), v.end()));
}


// Method 2 (Own Iterator)
bool next_perm(vector<int>& v) {

    size_t longest = 1;
    int previous = v[v.size()-1];

    // Find longest non increasing contiguous subsequence
    for (int i = v.size()-2; i >= 0; i--) {
        if (v[i] <= previous) {
            break;
        } else {
            previous = v[i];
            longest++;
        }
    }

    // No next permutation as this is the last permutation
    if (longest == v.size()) {
        return false;
    } else {
        int p_idx = v.size() - (longest + 1);
        int j = p_idx;
        for (int i = v.size() - 1; i > p_idx; i--) {
            if (v[i] > v[p_idx]) {j = i; break;}
        }

        swap(v[j], v[p_idx]);
        reverse(v.begin() + p_idx + 1, v.end());
    }

    return true;
}

void permutation3(vector<int>& v, int n) {
    for (int i = 0; i < n; i++) {
        v.push_back(i);
    }

    do {
        for (auto& e : v) {cout << e << " ";}
        cout << "\n";
    } while (next_perm(v));
}


// Backtracking: N-queens problem
void n_queens(vector<pair<int,int>>& queens,
            vector<bool>& cols,
            vector<bool>& diag1,
            vector<bool>& diag2,
            int n, int y, vector<vector<string>>& positions) {
    if (y == n) {
        vector<string> board{};
        for(auto& q : queens) {
            string s(n, '.');
            s[q.first] = 'Q';
            board.push_back(s);
        }
        positions.push_back(board);
    } else {
        for (int x = 0; x < n; x++) {
            if (cols[x] || diag1[x+y] || diag2[x-y+n-1]) {continue;}
            cols[x] = diag1[x+y] = diag2[x-y+n-1] = true;
            queens.push_back({x,y});
            n_queens(queens, cols, diag1, diag2, n, y+1, positions);
            queens.pop_back();
            cols[x] = diag1[x+y] = diag2[x-y+n-1] = false;
        }
    }
}

int main(int argc, char** argv) {
    
    /*
    vector<int> v{};
    
    subset1(v, 0, 3);
    subset2(v, 3);

    cout << "\n";

    vector<bool> ch(3, false);
    permutation1(v, ch, 3);
    cout << "\n";
    permutation2(v, 3);
    */

    // vector<int> v{};
    // permutation3(v,4);

    int n = 9;

    vector<pair<int, int>> queens;
    vector<bool> cols(n, false);
    vector<bool> diag1(n*n-1, false);
    vector<bool> diag2(n*n-1, false);

    vector<vector<string>> boards;
    n_queens(queens, cols, diag1, diag2, n, 0, boards);

    for(auto& board : boards) {
        for (auto& row : board) {
            cout << row << "\n";
        }
        cout << "\n";
    }

    return 0;
}