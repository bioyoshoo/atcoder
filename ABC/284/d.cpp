#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const ll MAX = 1e7;

vector<bool> erastotenes(ll N) {
    vector<bool> res(N + 1, true);
    res[1] = res[0] = false;
    for (ll x = 2; x <= N; x++) {
        if (!res[x]) continue;
        for (ll y = 2 * x; y <= N; y += x) res[y] = false;
    }
    return res;
}

int main() {
    int T; cin >> T;
    vector<bool> is_prime = erastotenes(MAX);

    // set<ll> prime_power;
    // for (ll x = 2; x <= MAX; x++) {
    //     if (is_prime[x]) prime_power.insert(1LL * x * x);
    // }

    rep(t, T) {
        ll N; cin >> N;
        bool ok = false;

        // p < q
        for (ll p = MAX; p >= 2; p--) {
            if (!is_prime[p]) continue;
            if ((N % (1LL * p * p)) != 0) continue;
            
            ll q = N / (1LL * p * p);

            if ((p < q) && (q >= 2)) {
                cout << p << " " << q << endl;
                ok = true;
                break;
            } 
        }

        if (ok) continue;

        // p > q
        for (ll q = MAX; q >= 2; q--) {
            if (!is_prime[q]) continue;
            if (N % q != 0) continue;
            // if (!prime_power.count(N / q)) continue;

            ll p = sqrt(N / q);
            if ((p * p) != (N / q)) continue;

            if (p > q && p >= 2) {
                cout << p << " " << q << endl;
                break;
            }
        }
    }
}
