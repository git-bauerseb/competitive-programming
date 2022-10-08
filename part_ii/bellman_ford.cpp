#include <bits/stdc++.h>

using namespace std;


vector<pair<int, int>> adj_l[5];


void add_edge(int a, int b, int weight, bool undirected) {
    adj_l[a].push_back({b, weight});

    if (undirected) {
        adj_l[b].push_back({a, weight});
    }
}


// Time complexity: O(nm)
//                  n: number of nodes
//                  m: number of edges
void bellman_ford(int s) {
    int n = 5;
    vector<int> distance(7, numeric_limits<int>::max());

    distance[s] = 0;

    for (int i = 1; i < n; i++) {
        for (auto& e: adj_l[i]) {
            int a, b, w;

            a = i;
            b = e.first;
            w = e.second;
            distance[b] = min(distance[b], distance[a] + w);

            if (distance[b] > distance[a] + w) {
                distance[b] = distance[a] + w;

                if (i == (n-1)) {
                    cout << "Graph contains negative cycle.\n";
                }
            }
        }
    }

    for (int i = 1; i < n; i++) {
        cout << "Node " << s << " -> " << i << ": " << distance[i] << "\n";
    }
}


struct Comparator {
    bool operator()(pair<int,int> const& a, pair<int,int> const& b) {
        return a.second > b.second;
    }
};

// Dijkstra algorithm for finding shortest path
// Time complexity: O(|V| + |E|log(|V|))
void dijkstra(int s) {
    int n = 6;

    vector<int> distances(6, numeric_limits<int>::max());
    vector<bool> processed(6, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, Comparator> queue;

    distances[s] = 0;
    queue.push({s, 0});

    while (!queue.empty()) {

        pair<int, int> top = queue.top();
        queue.pop();

        // Already processed node should not be considered anymore
        if (processed[top.first]) {
            continue;
        }

        processed[top.first] = true;

        for (auto u : adj_l[top.first]) {
            int start = top.first;
            int end = u.first;
            int weight = u.second;

            // If o----->start and then start ---> end is shorter
            // than o-----> end then update
            if (distances[start] + weight < distances[end]) {
                distances[end] = distances[start] + weight;
                queue.push({end, distances[end]});
            }
        }

    }

    for (int i = 1; i < n; i++) {
        cout << "Node " << s << " -> " << i << ": " << distances[i] << "\n";
    }
}

int main() {


    /*
    add_edge(1,2,3,true);
    add_edge(1,3,5,true);
    add_edge(3,2,2,true);
    add_edge(3,4,-7,true);
    add_edge(2,4,1,true);

    bellman_ford(1);
    */

    add_edge(1,2,5,true);
    add_edge(1,4,9,true);
    add_edge(2,3,2,true);
    add_edge(3,4,6,true);
    add_edge(4,5,2,true);
    add_edge(1,5,1,true);
    dijkstra(1);

    return 0;
}