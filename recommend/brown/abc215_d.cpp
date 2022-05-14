#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<ll, ll>> prime_factorize(ll n) {
    vector<pair<ll, ll>> res;
    for (ll a = 2; a * a <= n; a++) {
        if (n % a == 0) {
            ll exp = 0;
            while (n % a == 0) {
                exp++;
                n /= a;
            }
            res.push_back({a, exp});
        }
    }
    if (n > 1) res.push_back({n, 1});
    return res;
}

int main() {
    int N, M;
    cin >> N >> M;
    set<int> mp;
    for (int i = 0; i < N; i++) {
        ll a; cin >> a;
        vector<pair<ll, ll>> res = prime_factorize(a);
        for (auto r: res) mp.insert(r.first);
    }
    vector<bool> ans(M + 1, true);
    int m = M;
    for (int r:  mp) {
        for (int i = r; i <= M; i += r) {
            if (ans.at(i)) {
                ans.at(i) = false;
                m--;
            }
        }
    }
    cout << m << endl;
    for (int a = 1; a <= M; a++) if (ans.at(a)) cout << a << endl;
}