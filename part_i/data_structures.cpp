#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {

    vector<int> v;
    v.push_back(3);
    v.push_back(2);
    v.push_back(5);

    for(auto e: v) {cout << e << "\n";}

    string a = "hatti";
    string b = a + a;
    cout << b << "\n";

    b[5] = 'v';
    cout << b << "\n";

    string c = b.substr(3,4);
    cout << c << "\n";

    set<int> s;
    s.insert(3);
    s.insert(2);
    s.insert(5);
    cout << s.count(3) << "\n";
    cout << s.count(4) << "\n";

    s.erase(3);
    s.insert(4);

    cout << s.count(3) << "\n";
    cout << s.count(4) << "\n";

    s = {2,5,6,8,2};
    cout << s.size() << "\n";
    for (auto x : s) {
        cout << x << "\n";
    }

    cout << "\n";

    multiset<int> ms;
    ms.insert(5);
    ms.insert(5);
    ms.insert(5);
    cout << ms.count(5) << "\n";

    map<string, int> m;
    m["monkey"] = 4;
    m["banana"] = 3;
    
    cout << m["banana"] << "\n";

    for (auto x : m) {cout<< x.first << " " << x.second << "\n";}


    set<int> some_set = {9,8,7,6,5,4,3,2,1};

    auto it = some_set.end();
    cout << *(it--) << "\n";

    cout << "\n";

    // Right to left
    bitset<10> bs(string("0010011010"));

    cout << bs[2] << "\n";  // 0
    cout << bs[3] << "\n";  // 1

    // Number of '1' in bitset
    cout << bs.count() << "\n"; // 4

    return 0;
}