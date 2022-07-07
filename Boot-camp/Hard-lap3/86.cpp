#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using mint = modint1000000007;

int main() {
    int N; cin >> N;
    string S1, S2; cin >> S1 >> S2;
    vector<int> V;
    for (int i = 0; i < N;) {
        if (i + 1 < N && S1[i] == S1[i + 1]) {
            i += 2;
            V.push_back(0);
        }
        else {
            i += 1;
            V.push_back(1);
        }
    }

    int n = V.size();
    mint dp[100];
    if (V[0] == 0) dp[0] = 6;
    else dp[0] = 3;
    
    rep(i, n - 1) {
        if (V[i] == 0 && V[i + 1] == 0) dp[i + 1] = 3 * dp[i];
        else if (V[i] == 0 && V[i + 1] == 1) dp[i + 1] = dp[i];
        else if (V[i] == 1) dp[i + 1] = 2 * dp[i];
    }
    cout << dp[n - 1].val() << endl;
}