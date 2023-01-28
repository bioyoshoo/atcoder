#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int d, n, m; cin >> d >> n >> m;
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
