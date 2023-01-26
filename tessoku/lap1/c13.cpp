#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const int mod = 1000000007;

ll modpow(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    int N, P; cin >> N >> P;
    vector<ll> A(N); rep(i, N) cin >> A[i];
    map<int, int> mp;
    rep(i, N) mp[A[i] % mod] += 1;

    ll ans = 0;
    for (auto [res1, ignore]: mp) {
        int res2 = P * modpow(res1, mod - 2) % mod;

        if (res1 == res2) ans += 1LL * mp[res1] * (mp[res1] - 1);
        else ans += 1LL * mp[res1] * mp[res2];

        // 0 との組み合わせ
        if (res1 != 0 && res2 != 0) {
            ans += 1LL * mp[res1] * mp[0];
        }
        else if (res1 == 0) {
            ans += 1LL * mp[res1] * (N - mp[res1]);
        }
    }
    ans /= 2;

    cout << ans << endl;
}
