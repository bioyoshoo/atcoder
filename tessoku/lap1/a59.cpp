#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

class SegTree {
    public:
    int dat[300000], siz = 1;

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
            dat[pos] = dat[2 * pos] + dat[2 * pos + 1];
        }
    }

    int query(int l, int r, int a, int b, int u) {
        if (r <= a || b <= l) return 0;
        if (l <= a && b <= r) return dat[u];

        int m = (a + b) / 2;
        int L = query(l, r, a, m, 2 * u);
        int R = query(l, r, m, b, 2 * u + 1);
        return L + R;
    }
};

int main() {
    int N, Q; cin >> N >> Q;
    SegTree Z; Z.init(N);

    rep(i, Q) {
        int q; cin >> q;
        if (q == 1) {
            int pos, x; cin >> pos >> x;
            Z.update(pos, x);
        }
        else if (q == 2) {
            int l, r; cin >> l >> r;
            cout << Z.query(l, r, 1, Z.siz + 1, 1) << endl;
        }
    }
}
