#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int n = S.size();

    map<char, int> mp;
    for (char c: S) mp[c]++;

    int c_max = -1, c_min = 1e6;
    for (auto m: mp) {
        c_max = max(c_max, m.second);
        c_min = min(c_min, m.second);
    }

    if (mp.size() == 3 && c_max - c_min <= 1) cout << "YES" << endl;
    else if (mp.size() == 2 && n == 2) cout << "YES" << endl;
    else if (n == 1) cout << "YES" << endl;
    else cout << "NO" << endl;
}