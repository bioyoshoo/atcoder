#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    map<string, vector<pair<int, int>>> mp;
    rep(i, N) {
        string s; cin >> s;
        int p; cin >> p;
        mp[s].push_back({p, i + 1});
    }

    for (auto m: mp) {
        vector<pair<int, int>> V = m.second;
        sort(V.rbegin(), V.rend());
        for (auto v: V) {
            cout << v.second << endl;
        }
    }
}