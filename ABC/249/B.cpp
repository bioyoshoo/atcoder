#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;

    map<char, int> mp;
    for (char c: S) mp[c]++;

    bool cap = false, low = false, diff = true;
    for (auto m: mp) {
        if ((m.first - 'a') >= 0  && (m.first - 'a') < 26) low = true;
        if ((m.first - 'A') >= 0  && (m.first - 'A') < 26) cap = true;
        if (m.second > 1) diff = false;
    }

    if (cap && low && diff) cout << "Yes" << endl;
    else cout << "No" << endl;
}