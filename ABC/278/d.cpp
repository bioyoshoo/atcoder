#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<ll> A(N); rep(i, N) cin >> A[i];
    int Q; cin >> Q;
    ll x = -1;
    map<int, ll> mp, empty_map;

    rep(i, Q) {
        int q; cin >> q;
        if (q == 1) {
            cin >> x;
            // 初期化
            mp = empty_map;
        }
        if (q == 2) {
            int idx; ll y; cin >> idx >> y; idx--;
            mp[idx] += y;
        }
        if (q == 3) {
            int idx; cin >> idx; idx--;
            if (x == -1) cout << A[idx] + mp[idx] << endl;
            else cout << x + mp[idx] << endl;
        }
    }
}
