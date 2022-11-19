#include <bits/stdc++.h>

using namespace std;

vector<int> adj[7];
bool visited[6];


void add_edge(int a, int b, bool undirected) {
    adj[a].push_back(b);
    if (undirected) {
        adj[b].push_back(a);
    }
}    

// Depth-first search in graph
// Time complexity: O(n + m)
void dfs(int start) {
    if (visited[start]) {
        return;
    } else {
        cout << "Visiting " << start << "\n";
        visited[start] = true;

        for(auto& neighbour : adj[start]) {
            dfs(neighbour);
        }

    }
}


// Breadth-first search (BFS)
// Time complexity: O(n + m)
void bfs(int start) {
    queue<int> queue{};

    queue.push(start);
    visited[start] = true;

    cout << "Visited " << start << "\n"; 

    while (!queue.empty()) {

        int current = queue.front();
        queue.pop();

        for(auto& neighbour : adj[current]) {

            if (visited[neighbour]) {
                continue;
            }

            visited[neighbour] = true;
            queue.push(neighbour);

            cout << "Visited " << neighbour << "\n"; 
        }
    }
}

int main() {

    /*
        add_edge(1,2, true);
        add_edge(2,5, true);
        add_edge(2,3, true);
        add_edge(5,3, true);

        add_edge(1,4, true);
        dfs(1);
    */

    add_edge(1,2,true);
    add_edge(1,4,true);
    add_edge(2,3,true);
    add_edge(2,5,true);
    add_edge(5,6,true);
    add_edge(3,6,true);

    bfs(1);


    return 0;
}