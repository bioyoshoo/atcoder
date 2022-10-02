#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using Graph = vector<vector<int>>;

int main() {
    int N, Q; cin >> N >> Q;

    Graph G(N);
    rep(i, N) {
        int L; cin >> L;
        rep(j, L) {
            int a; cin >> a;
            G[i].push_back(a);
        }
    }

    rep(i, Q) {
        int s, t; cin >> s >> t; s--; t--;
        cout << G[s][t] << endl;
    }
}