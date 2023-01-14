#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int T, N; cin >> T >> N;
    vector<int> V(T + 1);
    rep(i, N) {
        int l, r; cin >> l >> r;
        V[l] += 1; V[r] -= 1;
    }
    for (int i = 1; i <= T; i++) V[i] += V[i - 1];

    rep (i, T) cout << V[i] << endl;
}
