#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

vector<ll> Divisors(ll N) {
    vector<ll> res;
    for (ll a = 1; a*a <= N; a++) {
        if (N % a != 0) continue;
        res.push_back(a);
        if (a != N / a) res.push_back(N / a);
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
    ll N; cin >> N;
    vector<ll> res = Divisors(N);

    for (auto a: res) cout << a << endl;
}
