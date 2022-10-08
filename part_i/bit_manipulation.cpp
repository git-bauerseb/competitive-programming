#include <bits/stdc++.h>

using namespace std;

bool is_power_of_four(int n) {
    return !(n & (n-1)) && (n & 0x5555555555);
}

int get_sum(int a, int b) {
    return b == 0 ? a : get_sum(a^b, (a&b) << 1);
}

int main(int argc, char** argv) {

    /*
    int a = 0b0100'0010;
    int b = 0b1001'1110;

    // 1101 1110
    cout << std::bitset<8>(a | b) << "\n";


    // 0000 0010
    cout << std::bitset<8>(a & b) << "\n";


    // 0100 0000
    cout << std::bitset<8>(a & (~b)) << "\n";

    // 1011 1101
    cout << std::bitset<8>(~a) << "\n";


    // 1011 1101
    cout << std::bitset<8>(0b11 & ~0b11) << "\n";

    for (int i = 0; i <= 65536; i++) {
        if (is_power_of_four(i)) {
            cout << i << "\n";
        }
    }
    */
   

    /*
    cout << get_sum(4, 7) << "\n";
    cout << get_sum(-4, 7) << "\n";
    cout << get_sum(4, -7) << "\n";

    // Swap without helper
    int x = 42;
    int y = 3748;

    x ^= y;
    y ^= x;
    x ^= y;

    cout << x << "\n";
    cout << y << "\n";
    */

    return 0;
}