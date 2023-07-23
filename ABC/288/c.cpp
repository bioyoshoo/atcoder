#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, M; cin >> N >> M;
    vector<set<int>> V(M);
    rep(i, M) {
        int c; cin >> c;
        rep(j, c) {
            int a; cin >> a; V[i].insert(a);
        }
    }

    ll ans = 0;
    for (ll i = 0; i < (1LL << M); i++) {
        vector<int> selected;
        rep(j, M) {
            if (i & (1LL << j)) selected.push_back(j);
        }

        vector<bool> check(N + 1, false);
        for (auto s: selected) {
            for (int n = 1; n <= N; n++) if (V[s].count(n)) check[n] = true;
        }

        bool ok = true;
        for (int n = 1; n <= N; n++) if (!check[n]) ok = false;

        if (ok) ans++;
    }

    cout << ans << endl;
}