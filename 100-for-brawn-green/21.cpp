#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<ll> H(N), S(N);
    rep(i, N) cin >> H[i] >> S[i];

    ll l = 0, r = 8e18;
    while (r - l > 1) {
        ll x = (r + l) / 2;

        bool flag = true;

        vector<ll> T(N);
        rep(i, N) {
            if (x < H[i]) flag = false;
            T[i] = (x - H[i]) / S[i];
        }
        sort(T.begin(), T.end());
        rep(i, N) if (i > T[i]) flag = false;

        if (flag) r = x;
        else l = x;
    }
    cout << r << endl;
}