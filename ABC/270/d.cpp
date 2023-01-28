#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

template<class T> bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    else return false;
}

int main() {
    int N, K; cin >> N >> K;
    vector<int> A(K);
    rep(i, K) cin >> A[i];

    vector<ll> dp(N + 1);
    
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j < K; j++) {
            if (i - A[j] >= 0) chmax(dp[i], i - dp[i - A[j]]);
        }
    }

    cout << dp[N] << endl;
}
