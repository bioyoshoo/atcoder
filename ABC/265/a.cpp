#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int X, Y, N; cin >> X >> Y >> N;
    int ans = 1e9;

    for (int i = 0; i <= N / 3; i++) {
        int cand = Y * i + X * (N - 3*i);
        ans = min(ans, cand);
    }

    cout << ans << endl;
}