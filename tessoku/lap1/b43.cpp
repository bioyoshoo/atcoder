#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, M; cin >> N >> M;
    vector<int> ans(N, M);
    rep(i, M) {
        int a; cin >> a; a--;
        ans[a] -= 1;
    }

    rep(i, N) cout << ans[i] << endl;
}
