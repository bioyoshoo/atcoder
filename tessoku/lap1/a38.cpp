#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const int INF = 24;

int main() {
    int D, N; cin >> D >> N;
    vector<int> T(D, INF);

    rep(i, N) {
        int L, R, H; cin >> L >> R >> H; L--, R--;
        for (int x = L; x <= R; x++) T[x] = min(T[x], H);
    }

    ll ans = 0;
    rep(i, D) ans += T[i];

    cout << ans << endl;
}