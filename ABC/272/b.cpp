#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, M; cin >> N >> M;
    vector<vector<bool>> T(N, vector<bool>(N, false));

    rep(i, M) {
        int k; cin >> k;
        vector<int> V(k);
        rep(j, k) {
            int x; cin >> x; x--;
            V[j] = x; 
        }
        for (int a = 0; a < k; a++) {
            for (int b = a + 1; b < k; b++) {
                T[V[a]][V[b]] = true; T[V[b]][V[a]] = true;
            }
        }
    }

    bool ans = true;
    rep(i, N) {
        rep(j, N) {
            if (i == j) continue;
            if (!(T[i][j])) ans = false;
        }
    }

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}