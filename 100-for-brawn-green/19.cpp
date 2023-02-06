#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int d, n, m; cin >> d >> n >> m;
    vector<int> dist(n + 1);
    dist[n] = d;
    rep(i, n - 1) cin >> dist[i + 1];
    sort(dist.begin(), dist.end());
    vector<int> K(m);
    rep(i, m) cin >> K[i];

    ll ans = 0;
    rep(i, m) {
        int l = 0, r = n;
        while (r - l > 1) {
            int mid = (r + l) / 2;

            if (dist[mid] < K[i]) l = mid;
            else r = mid;
        }
        ans += min(abs(dist[l] - K[i]), abs(dist[r] - K[i]));
    }

    cout << ans << endl;
}
