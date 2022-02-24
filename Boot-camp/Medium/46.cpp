#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    map<char, int> M;
    M['a'] = 0;
    M['b'] = 0;
    M['c'] = 0;
    for (char c: S) M.at(c)++;

    vector<int> V = { M.at('a'), M.at('b'), M.at('c') };
    sort(V.begin(), V.end());

    if (V.at(2) - 1 > V.at(0) + V.at(1)) cout << "NO" << endl;
    else if (V.at(2) - 1 == V.at(1) && V.at(0) == 0) cout << "NO" << endl;
    else cout << "YES" << endl;
}