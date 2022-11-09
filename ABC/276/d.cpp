#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const ll INF = 1e18;

vector<pair<ll, int>> factorize(ll n) {
    vector<pair<ll, ll>> res;
    for (ll a = 2; a * a <= n; a++) {
        if (n % a == 0) continue;
        int exp = 0;
        while (n % a == 0) {
            exp++;
            n /= a;
        }
        res.push_back({a, exp});
    }
    if (n > 1) res.push_back({n, 1});
    return res;
}

int main() {
    int N; cin >> N;
    vector<int> A(N); rep(i, N) cin >> A[i];

    set<int> cand;
    


    bool same = true;
    for (int i = 0; i < N - 1; i++) if (A[i] != A[i + 1]) same = false;

    if (same) cout << 0 << endl;
    else {
        ll ans = INF;
        for (auto x: cand) {

            ll y = 0;
            bool flag = true;
            rep(i, N) {
                if (A[i] % x != 0) {
                    flag = false;
                    break;
                }
                if (A[i] < x) {
                    flag = false;
                    break;
                }
                if ((A[i] > 1) && (A[i] % 2 != 0) && (A[i] % 3 != 0)) {
                    flag = false;
                    break;
                }

                int div = A[i] / x;
                while (div % 2 == 0) {
                    y++;
                    div /= 2;
                }
                while (div % 3 == 0) {
                    y++;
                    div /= 3;
                }
            }

            if (flag) ans = min(y, ans);
        }

        if (ans == INF) cout << -1 << endl;
        else cout << ans << endl;
    }
}
