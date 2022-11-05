#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const int M = 1e4;

int main() {
    int N, x, y; cin >> N >> x >> y;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    bool dp1[2*M + 1], dp2[2*M + 1], dp3[2*M + 1];

    dp1[A[0] + M] = dp2[0 + M] = true;

    for (int i = 1; i < N; i++) {

        for (int j = -M; j <= M; j++) dp3[j] = false;

        if (i % 2 == 0) {
            for (int j = -M; j <= M; j++) {
                if (j - A[i] >= -M) dp3[j - A[i] + M] |= dp1[j + M];
                if (j + A[i] <= M) dp3[j + A[i] + M] |= dp1[j + M];
            }
            swap(dp1, dp3);
        }
        else {
            for (int j = -M; j <= M; j++) {
                if (j - A[i] >= -M) dp3[j - A[i] + M] |= dp2[j + M];
                if (j + A[i] <= M) dp3[j + A[i] + M] |= dp2[j + M];
            }
            swap(dp2, dp3);
        }
    }

    if (dp1[x + M] && dp2[y + M]) cout << "Yes" << endl;
    else cout << "No" << endl;
}
