#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ld = long double;

int main() {
    int N, K; cin >> N >> K;
    vector<int> A(N); rep(i, N) cin >> A[i];

    double L = 0, R = 1e9 + 1;
    while (R - L > 1e-6) {
        ld x = (L + R) / 2; // 最も低いボーダーの値で二分検索

        int cnt = 0;
        rep(i, N) cnt += (int)(A[i] / x);

        if (cnt > K) L = x;
        else if (cnt < K) R = x;
        else break;
    }

    double x = (L + R) / 2;
    vector<int> ans(N);
    rep(i, N) ans[i] = (int)(A[i] / x);

    rep(i, N) cout << ans[i] << " ";
    cout << endl;
}
