#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

bool dp[100010];

int main() {
    int N; cin >> N;
    vector<int> A(N); rep(i, N) cin >> A[i];
    int M; cin >> M;
    set<int> B;
    rep(i, M) {
        int b; cin >> b; B.insert(b);
    }
    int X; cin >> X;

    rep(i, 100010) dp[i] = false;
    dp[0] = true;

    for (int i = 0; i <= X; i++) {
        for (int j = 0; j < N; j++) {
            // i - A[j] -> i
            if (i - A[j] < 0) continue;
            if (B.count(i - A[j])) continue;
            if (B.count(i)) continue;

            if (dp[i - A[j]]) dp[i] = true;
        }
    }

    if (dp[X]) cout << "Yes" << endl;
    else cout << "No" << endl;
}
