#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int Q; cin >> Q;
    multiset<ll> s;

    rep(i, Q) {
        int q; ll x; cin >> q >> x;

        if (q == 1) s.insert(x);
        else {
            int k; cin >> k;

            if (q == 2) {
                auto it = s.upper_bound(x);

                bool ok = true;
                rep(j, k) {
                    if (it == s.begin()) {
                        ok = false;
                        break;
                    }
                    it--;
                }
                if (ok) cout << *it << endl;
                else cout << -1 << endl;
            }
            else if (q == 3) {
                auto it = s.lower_bound(x);

                bool ok = true;
                rep(j, k - 1) {
                    if (it == s.end()) {
                        ok = false;
                        break;
                    }
                    it++;
                }
                if (ok && it != s.end()) cout << *it << endl;
                else cout << -1 << endl;
            }
        }
    }
}
