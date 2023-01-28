#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const int INF = 1e9;

class SegTree {
    public:
    int dat[300000], siz = 1;

    void init(int N) {
        siz = 1;
        while (siz < N) siz *= 2;
        for (int i = 1; i < siz * 2; i++) dat[i] = INF;
    }

    void update(int pos, int x) {
        pos = pos + siz - 1;
        dat[pos] = x;
        while (pos >= 2) {
            pos /= 2;
            dat[pos] = min(dat[2*pos], dat[2*pos + 1]);
        }
    }

    // [l, r) 求めたい区間, [a, b) 現在のセルの区間, u 現在のセル番号
    int query(int l, int r, int a, int b, int u) {
        if (r <= a || b <= l) return INF;
        if (l <= a && b <= r) return dat[u];
        int m = (a + b) / 2;
        int L = query(l, r, a, m, 2*u);
        int R = query(l, r, m, b, 2*u + 1);
        return min(L, R);
    }
};

int main() {
    int N, L, R; cin >> N >> L >> R;
    vector<int> X(N + 1); rep(i, N) cin >> X[i + 1];

    vector<int> dp(N + 1);
    for (int i = 1; i <= N; i++) dp[i] = INF;
    dp[1] = 0;

    SegTree Z;
    Z.init(N);
    Z.update(1, dp[1]);

    for (int i = 2; i <= N; i++) {
        // idx の範囲が [L, R)
        int idx1 = lower_bound(X.begin() + 1, X.end(), X[i] - R) - X.begin();
        int idx2 = lower_bound(X.begin() + 1, X.end(), X[i] - L + 1) - X.begin();

        dp[i] = Z.query(idx1, idx2, 1, Z.siz + 1, 1) + 1;
        Z.update(i, dp[i]);
    }

    cout << dp[N] << endl;
}
