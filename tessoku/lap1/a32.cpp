#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, A, B; cin >> N >> A >> B;

    vector<bool> dp(N + 1, false);

    for (int i = 0; i <= N; i++) {
        if (i - A >= 0 && !dp[i - A]) dp[i] = true;
        if (i - B >= 0 && !dp[i - B]) dp[i] = true;
    }

    if (dp[N]) cout << "First" << endl;
    else cout << "Second" << endl;
}