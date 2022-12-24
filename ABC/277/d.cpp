#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int N, M;
set<int> st;
map<int, ll> mp, dp;
ll rec(int x) {
    if (!st.count(x)) return 0;
    if (dp[x] != -1) return dp[x];
    return dp[x] = mp[x] * x + rec((x + 1) % M);
}

int main() {
    cin >> N >> M;

    ll sum = 0;
    rep(i, N) {
        ll a; cin >> a;
        mp[a]++;
        dp[a] = -1;
        sum += a;
        st.insert(a);
    }

    ll ans = 1e18;
    for (auto m: mp) {
        ans = min(ans, sum - rec(m.first));
    }

    cout << ans << endl;
}
