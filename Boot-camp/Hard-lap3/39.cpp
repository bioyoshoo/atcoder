#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    string S; cin >> S;
    vector<int> V(N + 1);
    rep(i, N) if (S[i] == '#') V[i + 1] = 1;
    for (int i = 1; i < N + 1; i++) V[i] += V[i - 1];

    int ans = 2e5;
    rep(i, N + 1) {
        int L = V[i];
        int R = (N - i) - (V[N] - V[i]);
        ans = min(ans, L + R);
    }
    cout << ans << endl;
}