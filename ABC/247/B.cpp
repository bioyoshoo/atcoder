#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<string, string>> V(N);
    map<string, int> mp;
    for (int i = 0; i < N; i++) {
        string s, t;
        cin >> s >> t;
        V.at(i) = {s, t};
        mp[s]++;
        mp[t]++;
    }

    bool ans = true;
    for (int i = 0; i < N; i++) {
        string s = V[i].first, t = V[i].second;
        if (!((mp[s] == 1) || (mp[t] == 1))) ans = false;
    }

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}