#include <bits/stdc++.h>

using namespace std;

int solutions = 0;

void hamilton(vector<bool> occupied, int n, int k, int x, int y) {
    if (k == n*n-1 && x == n-1 && y == n-1) {
        solutions++;
        return;
    } else if (k < n*n-1 && x == n-1 && y == n-1) {
        return;
    } else {

        // If touching wall check whether moving right or left is possible
        // If so, no solution can be found
        if (y == 0 || y == (n-1)) {
            if (x > 0 && !occupied[(x-1) + y*n] &&
                x < n-1 && !occupied[(x+1) + y*n]) {
                    return;
                }
        }

        if (x > 0 && !occupied[(x-1) + y * n]) {
            occupied[(x-1) + y * n] = true;
            hamilton(occupied, n, k+1, x-1, y);
            occupied[(x-1) + y * n] = false;
        }

        if (x < (n-1) && !occupied[(x+1) + y * n]) {
            occupied[(x+1) + y * n] = true;
            hamilton(occupied, n, k+1, x+1, y);
            occupied[(x+1) + y * n] = false;
        }

        if (y > 0 && !occupied[x + (y-1) * n]) {
            occupied[x + (y-1) * n] = true;
            hamilton(occupied, n, k+1, x, y-1);
            occupied[x + (y-1) * n] = false;
        }

        if (y < (n-1) && !occupied[x + (y+1) * n]) {
            occupied[x + (y+1) * n] = true;
            hamilton(occupied, n, k+1, x, y+1);
            occupied[x + (y+1) * n] = false;
        }
    }
}

int main(int argc, char** argv) {

    int n = 7;
    vector<bool> occ(n*n, false);
    occ[0] = true;
    occ[1] = true;

    hamilton(occ, n, 2, 1, 0);

    cout << 2*solutions << "\n";

    return 0;
}