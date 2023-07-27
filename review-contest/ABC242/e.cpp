#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using mint = modint998244353;

int main() {
    int T; cin >> T;
    rep(t, T) {
        int N; string S; cin >> N >> S;
        mint ans = 0;
        string synS = S;
        rep(i, (N + 1) / 2) {
            // S[i] より X[i] の方が小さい場合
            // 回文であればX[i]以降をどのように変えても回文になる
            if (S[i] > 'A') ans += (mint)(S[i] - 'A') * mint(26).pow((N + 1)/2 - i - 1);
            synS[i] = synS[N - 1 - i] = S[i];
        }
        
        cout << ans.val() << endl;
    }
}