#include <bits/stdc++.h>

using namespace std;


vector<int> adj_l[8];

void add_edge(int s, int e) {
    adj_l[s].push_back(e);
}


vector<int> c;

// Depth-first search for a tree
// s: current node
// e: previous node

// e ensures that search is only done at nodes that weren't visited
void dfs(int s, int e) {

    c[s] = 1;

    for (auto& desc : adj_l[s]) {
        if (desc == e) {continue;}

        dfs(desc, s);
        c[s] += c[desc];
    }

}

int main() {

    add_edge(2,5);
    add_edge(2,6);
    add_edge(2,1);
    add_edge(1,3);
    add_edge(1,4);
    add_edge(4,7);

    c.resize(7);

    dfs(1,0);

    return 0;
}