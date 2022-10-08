#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    vector<int> C(1e6+2);
    int n; cin >> n;
    rep(i, n) {
        int a, b; cin >> a >> b;
        C[a] += 1; C[b+1] -= 1;
    }

    rep(i, 1e6+2) C[i] += C[i - 1];

    int ans = -1;
    rep(c, 1e6+1) {
        if (ans < C[c]) ans = C[c];
    }

    cout << ans << endl;
}
