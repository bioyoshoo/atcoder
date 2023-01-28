#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const int MAX = 1e9;

template<class T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    else return false;
}

int main() {
    int N; cin >> N;
    vector<int> H(N); rep(i, N) cin >> H[i];
    vector<int> dp(N), prev(N, -1);

    dp.assign(N, MAX);
    dp[0] = 0;

    for (int i = 0; i < N; i++) {
        if (i > 0) {
            if (chmin(dp[i], dp[i - 1] + abs(H[i] - H[i - 1]))) prev[i] = i - 1;
        }
        if (i > 1) {
            if (chmin(dp[i], dp[i - 2] + abs(H[i] - H[i - 2]))) prev[i] = i - 2;
        }
    }

    vector<int> ans;
    int x = N - 1;
    while (prev[x] != -1) {
        ans.push_back(x + 1);
        x = prev[x];
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for (auto a: ans) cout << a << " ";
    cout << endl;
}
