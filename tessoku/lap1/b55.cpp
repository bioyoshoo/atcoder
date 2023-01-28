#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int Q; cin >> Q;
    set<int> S;

    rep(i, Q) {
        int q, x; cin >> q >> x;

        if (q == 1) S.insert(x);
        else if (q == 2) {
            if (S.empty()) cout << -1 << endl;
            else {
                auto iter = S.lower_bound(x);

                int a = abs(x - *iter);

                if (iter == S.begin()) cout << a << endl;
                else {
                    int b = abs(x - *prev(iter));
                    cout << min(a, b) << endl;
                }
            }
        }
    }
}
