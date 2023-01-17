#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

ll mod = 2147483647;
ll T1[100010], T2[100010];
ll B[100010];
ll H1[100010], H2[100010];

ll Hash_Value(int l, int r) {
    ll res = H1[r] - (B[r - l + 1] * H1[l - 1] % mod);
    if (res < 0) res += mod;
    return res;
}

ll revHash_Value(int l, int r) {
    ll res = H2[r] - (B[r - l + 1] * H2[l - 1] % mod);
    if (res < 0) res += mod;
    return res;
}

int main() {
    int N, Q; cin >> N >> Q;
    string S; cin >> S;

    for (int i = 1; i <= N; i++) T1[i] = 1LL*(S[i - 1] - 'a');
    reverse(S.begin(), S.end());
    for (int i = 1; i <= N; i++) T2[i] = 1LL*(S[i - 1] - 'a');

    B[0] = 1;
    for (int i = 1; i <= N; i++) B[i] = (100LL * B[i - 1]) % mod;

    H1[0] = 0; H2[0] = 0; 
    for (int i = 1; i <= N; i++) {
        H1[i] = (100LL * H1[i - 1]) % mod + T1[i];
        H2[i] = (100LL * H2[i - 1]) % mod + T2[i];
    }

    rep(i, Q) {
        int l, r; cin >> l >> r;

        ll h1 = Hash_Value(l, r);
        ll h2 = revHash_Value(N - r + 1, N - l + 1);

        if (h1 == h2) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
