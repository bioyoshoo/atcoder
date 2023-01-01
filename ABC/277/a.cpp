#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, X; cin >> N >> X;
    vector<int> P(N); rep(i, N) cin >> P[i];

    int ans = -1;
    rep(i, N) {
        if (P[i] == X) {
            ans = i + 1;
            break;
        }
    }
    cout << ans << endl;
}
