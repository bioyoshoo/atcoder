#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int n_digits(ll n) {
    return to_string(n).size();
}

int main() {
    ll N; cin >> N;
    vector<vector<int>> T(10, vector<int>(10));
    for (int n = 1; n <= N; n++) {
        int siz = n_digits(n);
        T[n / pow(10, siz - 1)][n % 10]++;
    }
    ll ans = 0;
    rep(a, 10) {
        rep(b, 10) {
            ans += T[a][b] * T[b][a];
        }
    }
    cout << ans << endl;
}