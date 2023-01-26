#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const ll INF = 1e17;

class SegTree {
    public:
    int siz = 1;
    ll dat[2100000];

    void init(int N) {
        siz = 1;
        while (siz < N) siz *= 2;
        for (int i = 1; i <= 2*siz; i++) dat[i] = INF;
    }

    void update(int pos, ll x) {
        pos = pos + siz - 1;
        if (dat[pos] <= x) return;
        dat[pos] = x;
        while (pos >= 2) {
            pos /= 2;
            dat[pos] = min(dat[2*pos], dat[2*pos + 1]);
        }
    }

    ll query(int l, int r, int a, int b, int u) {
        if (b <= l || r <= a) return INF;
        if (l <= a && b <= r) return dat[u];
        int m = (a + b) / 2;
        ll L = query(l, r, a, m, 2*u);
        ll R = query(l, r, m, b, 2*u + 1);
        return min(L, R);
    }
};

int main() {
    int N, L, K; cin >> N >> L >> K;
    vector<ll> A(N), C(N); rep(i, N) cin >> A[i] >> C[i];

    SegTree Z;
    Z.init(L);

    rep(i, N) {
        Z.update(A[i], C[i]);
    }

    ll ans = 0;
    for (int x = 1; x <= L - K; x++) {
        ll add = Z.query(x, x + K, 1, Z.siz + 1, 1);
        if (add == INF) {
            cout << -1 << endl;
            return 0;
        }
        ans += add;
    }

    cout << ans << endl;
    return 0;
}
