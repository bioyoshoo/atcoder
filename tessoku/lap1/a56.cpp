#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const ll mod = 2147483647;

ll T[200010], B[200010], H[200010];

// hash of S[l, r]
ll Hash(int l, int r) {
    ll h = H[r] - (B[r - l + 1] * H[l - 1] % mod);
    if (h < 0) h += mod;
    return h;
}

int main() {
    int N, Q; cin >> N >> Q;
    string S; cin >> S;

    rep(i, N) T[i + 1] = (ll)(S[i] - 'a');

    B[0] = 1;
    rep(i, N) B[i + 1] = 100LL * B[i] % mod;

    H[0] = 0;
    rep(i, N) H[i + 1] = (100LL * H[i] + T[i + 1]) % mod;


    rep(i, Q) {
        int a, b, c, d; cin >> a >> b >> c >> d;

        ll h1 = Hash(a, b);
        ll h2 = Hash(c, d);

        if (h1 == h2) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
