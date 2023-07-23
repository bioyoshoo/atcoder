#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const ll mod = 2147483647;

ll T[500010];

int main() {
    int N; cin >> N;
    vector<string> S(N); rep(i, N) cin >> S[i];
    vector<map<ll, int>> V(500010);

    rep(i, N) {
        ll H = 0;
        for (int j = 0; j < (int)S[i].size(); j++) {
            H = ((100LL * H) % mod) + (ll)(S[i][j] - 'a') % mod;
            H %= mod;
            V[j][H] += 1;
        }
    }

    vector<int> A;
    rep(i, N) {
        int ans = 0;
        ll H = 0;
        rep(j, (int)S[i].size()) {
            H = ((100LL * H) % mod) + (ll)(S[i][j] - 'a') % mod;
            H %= mod;
            if (V[j][H] >= 2) ans = j + 1;
        }
        A.push_back(ans);
    }

    rep(i, N) cout << A[i] << endl;
}