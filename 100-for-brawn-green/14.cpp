#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const ll INF = 1e18;

int main() {
    int N, K; cin >> N >> K;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    ll ans = INF;
    for (ll i = 0; i < (1LL << N); i++) {
        ll cand = 0;
        
        set<int> st;
        rep(j, N) if (i & (1LL << j)) st.insert(j);

        if ((int)st.size() != K) continue;

        int mx = 0;
        rep(j, N) {
            if (st.count(j)) {
                if (mx >= A[j]) {
                    cand += mx - A[j] + 1;
                    mx = mx + 1;
                }
                else {
                    mx = A[j];
                }
            }
            else {
                mx = max(mx, A[j]);
            }
        }

        ans = min(ans, cand);
    }

    cout << ans << endl;
}
