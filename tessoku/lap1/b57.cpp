#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int dp[31][300010];

int sum_digit(int n) {
    int res = 0;
    while (n > 0) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

int main() {
    int N, K; cin >> N >> K;

    for (int i = 0; i <= N; i++) {
        dp[0][i] = i - sum_digit(i);
    }

    for (int i = 0; i < 30; i++) {
        for (int j = 0; j <= N; j++) {
            dp[i + 1][j] = dp[i][dp[i][j]];
        }
    }

    vector<int> steps;
    int keta = 0;
    while (K > 0) {
        if (K & 1) steps.push_back(keta);
        K >>= 1;
        keta++;
    }

    for (int n = 1; n <= N; n++) {
        int ans = n;
        for (auto s : steps) {
            ans = dp[s][ans];
        }
        cout << ans << endl;
    }
}
