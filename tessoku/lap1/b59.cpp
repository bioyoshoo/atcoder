#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

class SegTree {
    public:
    ll dat[600010], siz = 1;

    void init(int N) {
        siz = 1;
        while (siz < N) siz *= 2;
        for (int i = 1; i < siz * 2; i++) dat[i] = 0;
    }

    void update(int pos, int x) {
        pos = pos + siz - 1;
        dat[pos] = x;
        while (pos >= 2) {
            pos /= 2;
            dat[pos] = dat[2*pos] + dat[2*pos + 1];
        }
    }

    ll query(int l, int r, int a, int b, int u) {
        if (r <= a || b <= l) return 0;
        if (l <= a && b <= r) return dat[u];
        int m = (a + b) / 2;
        ll L = query(l, r, a, m, 2*u);
        ll R = query(l, r, m, b, 2*u + 1);
        return L + R;
    }
};

int main() {
    int N; cin >> N;
    SegTree Z;
    Z.init(N);

    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        int a; cin >> a;

        Z.update(a, 1);
        ans += Z.query(a + 1, N + 1, 1, Z.siz + 1, 1);
    }

    cout << ans << endl;
}
