#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, M; cin >> N >> M;
    vector<vector<int>> T(N, vector<int>(M));
    vector<int> P(M);
    rep(i, M) {
        int k; cin >> k;
        rep(j, k) {
            int s; cin >> s; s--;
            T[s][i] = 1;
        }
    }
    rep(i, M) cin >> P[i];

    int ans = 0;
    for (ll i = 0; i < (1LL << N); i++) {
        vector<int> cnt(M);
        rep(j, N) {
            if (i & (1LL << j)) {
                rep(k, M) {
                    if (T[j][k] == 1) cnt[k]++;
                }
            }
        }

        bool flag = true;
        rep(j, M) if (cnt[j] % 2 != P[j]) flag = false;
        if (flag) ans++;
    }
    cout << ans << endl;
}