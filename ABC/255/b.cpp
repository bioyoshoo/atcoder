#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using ld = long double;
using cord = pair<ld, ld>;
#define rep(i, n) for (int i = 0; i < (n); i++)
const ll INF = 1e15;

int main() {
    int N, K; cin >> N >> K;
    vector<int> A(N);
    rep(i, K) {
        int a; cin >> a; a--;
        A[i] = a;
    }
    vector<cord> T(N);
    rep(i, N) cin >> T[i].first >> T[i].second;

    ld ans = 0;
    rep(j, N) {
        ld cand = INF;
        rep(i, K) {
            ld x1 = T[A[i]].first, y1 = T[A[i]].second;
            ld x2 = T[j].first, y2 = T[j].second;
            ld dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
            cand = min(cand, dist);
        }
        ans = max(ans, cand);
    }

    ans = sqrt(ans);
    cout << fixed << setprecision(10);
    cout << ans << endl;
}