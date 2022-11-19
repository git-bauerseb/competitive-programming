#include <bits/stdc++.h>

using namespace std;

// Storing (neighbour, weight)
vector<pair<int,int>> adj_l[5];


void add_edge(int s, int e, int w, bool undirected) {
    adj_l[s-1].push_back({e-1, w});

    if (undirected) {
        adj_l[e-1].push_back({s-1, w});
    }
}


int dists[5][5];

void floyd_warshall() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == j) {dists[i][j] = 0;}
            else {dists[i][j] = 10000;}
        }


        for(auto& e : adj_l[i]) {
            dists[i][e.first] = e.second;
        }
    }


    for (int k = 0; k < 5; k++) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                dists[i][j] = min(dists[i][k] + dists[k][j],
                                    dists[i][j]);
            }
        }
    }


    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << dists[i][j] << "\t";
        }

        cout << "\n";
    }
}

int main() {

    add_edge(1,2,5,true);
    add_edge(1,5,1,true);
    add_edge(2,3,2,true);
    add_edge(3,4,7,true);
    add_edge(1,4,9,true);
    add_edge(1,5,1,true);
    add_edge(4,5,2,true);

    floyd_warshall();


    return 0;
}