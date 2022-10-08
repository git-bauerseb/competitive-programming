#include <bits/stdc++.h>

using namespace std;

// Greedy coin problem
// Does not guarantee minimal solution
int solve_greedy(vector<int>& coins, int x) {
    sort(coins.rbegin(), coins.rend());
    int num = 0;
    while (x > 0) {
        
        for(auto& c : coins) {
            if (x >= c) {x -= c; break;}
        }

        num++;
    }

    return num;
}

// Dynamic programming
int solve_dynamic(vector<int>& coins, int x) {
    if (x < 0) {return 1 << 27;}
    if (x == 0) {return 0;}
    int best = 1 << 27;
    for (auto& c : coins) {
        best = min(best, solve_dynamic(coins, x - c) + 1);
    }

    return best;
}

int solve_dynamic_memo(vector<int>& coins, vector<int>& mem, int x) {
    if (x < 0) {return 1 << 27;}
    if (x == 0) {return 0;}
    if (mem[x] >= 0) {return mem[x];}
    int best = 1 << 27;
    for (auto& c : coins) {
        best = min(best, solve_dynamic_memo(coins, mem, x-c)+1);
    }

    mem[x] = best;
    return best;
}

int solve_dynamic_memo_iter(vector<int>& coins, vector<int>& mem, int x) {
    mem[0] = 0;
    for (int i = 1; i < mem.size(); i++) {
        mem[i] = 1 << 31;
        for(auto& c : coins) {
            if (x - c >= 0) {
                mem[x] = min(mem[x], mem[x-c]+1);
            }
        }
    }

    return mem[x];
}

// Get solution with DP and memorization
int solve_dynamic_memo_iter_sol(vector<int>& coins, vector<int>& mem, vector<int>& first, int x) {
    mem[0] = 0;
    for (int i = 1; i <= x; i++) {
        mem[i] = 1 << 30;
        for (auto c : coins) {
            if (i - c >= 0 && mem[i-c]+1 < mem[i]) {
                mem[i] = mem[i-c]+1;
                first[i] = c;
            }
        }
    }

    return mem[x];
}

int num_ways(vector<int>& coins, int x) {

    vector<int> mem(x+1,0);

    mem[0] = 1;

    for (int i = 1; i <= x; i++) {
        mem[i] = 0;
        for (auto& c : coins) {
            if (i - c >= 0) {
                mem[i] += mem[i - c];
            }
        }
    }

    return mem[x];
}

int longest_increasing_subsequence(vector<int>& nums) {
    int n = nums.size();
    vector<int> length(n, 0);

    length[0] = 1;
    int max_length = 1;

    for (int i = 1; i < n; i++) {
        length[i] = 1;
        for (int k = 0; k < i; k++) {
            if (nums[k] < nums[i]) {
                length[i] = max(length[i], length[k] + 1);
            }
        }

        max_length = max(max_length, length[i]);
    }
    
    return max_length;
}

int max_path(vector<vector<int>>& grid) {

    int n = grid.size();
    int m = grid[0].size();

    int sum[n+1][m+1];

    int path[n + m - 1];

    for (int i = 0; i < n+1; i++) {sum[i][0] = 0;}
    for (int j = 0; j < m+1; j++) {sum[0][j] = 0;}

    int idx = 0;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
           sum[y+1][x+1] = max(sum[y][x+1], sum[y+1][x]) + grid[y][x];
        }
    }

    int y = 1;
    int x = 1;

    while (y != n || x != m) {
        cout << grid[y-1][x-1] << " ";

        if (x >= m) {y++;}
        else if (y >= n) {x++;}
        else if (sum[y+1][x] > sum[y][x+1]) {
            y++;
        }
        else {x++;}
    }

    cout << grid[y-1][x-1] << "\n";

    return sum[n][m];
}

void knapsack_recursive(vector<int>& weights, set<int>& nums) {
    if (!weights.empty()) {
        // Include current weight
        int weight = weights[weights.size()-1];

        set<int> n_nums;
        for (auto& e : nums) {n_nums.insert(e + weight);}
        nums.insert(n_nums.begin(), n_nums.end());
        nums.insert(weight);

        weights.pop_back();
        knapsack_recursive(weights, nums);
        weights.push_back(weight);
    } 
}

void knapsack_recursive(vector<int>& weights) {
    set<int> nums;
    knapsack_recursive(weights, nums);

    for (auto& e  : nums) {
        cout << e << " ";
    }
}

void knapsack(vector<int>& weights) {
    int n = weights.size();
    int max_sum = 0;
    for (int i = 0; i < weights.size(); i++) {
        max_sum += weights[i];
    }

    vector<vector<bool>> mem(n+1, vector<bool>(max_sum+1));

    mem[0][0] = true;

    for (int k = 1; k <= n; k++) {
        for (int i = 0; i <= max_sum; i++) {
            if (i - weights[k-1] >= 0) {
                mem[k][i] = mem[k][i] || mem[k-1][i - weights[k-1]];
            }
            mem[k][i] = mem[k][i] || mem[k-1][i];
        }
    }

    for (int i = 0; i <= max_sum; i++) {
        if (mem[n][i]) {
            cout << i << " ";
        }
    }
}

/*
    Improved version of the knapsack problem that uses 1D-array
    for storing whether sum x can be formed.
*/
void knapsack_improved(vector<int>& weights) {
    int n = weights.size();
    int max_sum = 0;
    for (int i = 0; i < weights.size(); i++) {
        max_sum += weights[i];
    }

    vector<int> mem(max_sum);

    mem[0] = true;
    for (int k = 0; k <= n; k++) {
        for (int x = max_sum; x >= 0; x--) {
            if (mem[x]) {mem[x + weights[k]] = true;}
        }
    }

    for (int i = 0; i <= max_sum; i++) {
        if (mem[i]) {
            cout << i << "\n";
        }
    }

}

int levensthein_distance(string& a, string& b) {

    int n = a.size();
    int m = b.size();

    vector<vector<int>> dist(m+1, vector<int>(n+1));

    for (int i = 0; i < m+1; i++) {dist[i][0] = i;}
    for (int j = 0; j < n+1; j++) {dist[0][j] = j;}

    for (int i = 1; i < m+1; i++) {
        for (int j = 1; j < n+1; j++) {
            int cost = a[j-1] == b[i-1] ? 0 : 1;
            dist[i][j] = min(dist[i-1][j] + 1, 
                        min(dist[i][j-1] + 1, dist[i-1][j-1] + cost));
        }
    }

    return dist[m][n];
}

int main(int argc, char** argv) {

    string a("intention");
    string b("execution");
    int dist = levensthein_distance(a,b);
    cout << dist << "\n";
    return 0;
}