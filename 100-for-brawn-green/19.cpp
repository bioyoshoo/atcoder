#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int d, n, m; cin >> d >> n >> m;
<<<<<<< HEAD
    vector<int> D;
    D.push_back(0);
    rep(i, n - 1) {
        int d; cin >> d; D.push_back(d);
    }
    D.push_back(d);
    sort(D.begin(), D.end());

    int ans = 0;
    rep(i, m) {
        int k; cin >> k;

        int L = 0, R = n;
        while (R - L > 1) {
            int mid = (L + R) / 2;
            if (k >= D[mid]) L = mid;
            else R = mid;
        }
        ans += min(abs(D[L] - k), abs(D[R] - k));
    }
    cout << ans << endl;
}
=======
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
>>>>>>> bc9a185f6f7513da0bc977790ba6c67c254988b0
