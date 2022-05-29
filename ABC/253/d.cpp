#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

ll sum(ll n, ll N) {
    ll res;
    ll num = N / n;
    if (num == 0) res = 0;
    else res = (1 + num) * num / 2 * n;
    return res;
}

int main() {
    ll N, A, B; cin >> N >> A >> B;

    ll ans = (1 + N) * N / 2;
    ans -= sum(A, N);
    ans -= sum(B, N);
    ans += sum(lcm(A, B), N);
    cout << ans << endl;
}