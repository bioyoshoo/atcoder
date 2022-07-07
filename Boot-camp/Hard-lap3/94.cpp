#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using mint = modint1000000007;

mint C(int n, int k) {
    if (k < 0 || k > n) return 0;
    mint x = 1, y = 1;
    for (ll m = n; m >= n - k + 1; m--) x *= m;
    for (ll m = k; m >= 1; m--) y *= m;
    return x / y;
}

int main() {
    int N, K; cin >> N >> K;

    for (int g = 1; g <= K; g++) {
        mint div = C(K - 1, g - 1);
        mint put = C(N - K + 1, g);
        mint ans = div * put;
        cout << ans.val() << endl;
    }
}