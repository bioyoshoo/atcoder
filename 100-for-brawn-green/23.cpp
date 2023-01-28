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

    ll bottom = 0, ceil = 1e18;
    while (ceil - bottom > 1) {
        ll x = (bottom + ceil) / 2;

        bool flag = true;

        vector<ll> limit(N);
        rep(i, N) {
            if (x < H[i]) flag = false;
            limit[i] = (x - H[i]) / S[i];
        }

        if (flag) {
            sort(limit.begin(), limit.end());
            ll t = 0;
            rep(i, N) {
                limit[i] -= t;
                if (limit[i] < 0) {
                    flag = false;
                    break;
                }
                t += 1;
            }
        }

        if (flag) ceil = x;
        else bottom = x;
    }

    cout << ceil << endl;
}