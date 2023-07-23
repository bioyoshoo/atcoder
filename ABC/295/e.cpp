#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using mint = modint998244353;

mint C(int n, int k) {
    mint X = 1; for (int x = n; x > n - k; x--) X *= x;
    mint Y = 1; for (int y = k; y > 0; y--) Y *= y;
    return (mint)X/Y;
}

int main() {
    int N, M, K; cin >> N >> M >> K; K--;
    vector<int> A(N);
    int n0 = 0;
    rep(i, N) {
        cin >> A[i];
        if (A[i] == 0) n0++;
    }

    sort(A.begin(), A.end());

    int ak = A[K];
    mint ans = 0;
    // n0個の中からn0-m個がak以下, m個がakより大きくなる確率
    for (int m = 0; m <= n0; m++) {
        mint p1 = (mint)(ak)/M, p2 = 1 - p1;
        mint p = C(n0, m)*p1.pow(n0 - m)*p2.pow(m);

        if (K + m < N) ans += A[K + m]*p;
        else ans += (M - A[N - 1])/2 * p;
    }

    cout << ans.val() << endl;
}