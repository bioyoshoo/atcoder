#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const int MIN = -1e9;

template<class T> bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    else return false;
}

int main() {
    int N; cin >> N;
    vector<int> A(N - 1), B(N - 1);
    rep(i, N - 1) {
        cin >> A[i]; A[i]--;
    }
    rep(i, N - 1) {
        cin >> B[i]; B[i]--;
    }

    vector<ll> dp(N, MIN);
    dp[0] = 0;
    
    rep(i, N - 1) {
        chmax(dp[A[i]], dp[i] + 100);
        chmax(dp[B[i]], dp[i] + 150);
    }

    cout << dp[N - 1] << endl;
}
