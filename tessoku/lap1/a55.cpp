#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int Q; cin >> Q;
    set<int> st;

    rep(i, Q) {
        int q, x; cin >> q >> x;
        if (q == 1) {
            st.insert(x);
        }
        else if (q == 2) {
            st.erase(x);
        }
        else if (q == 3) {
            auto iter = st.lower_bound(x);
            if (iter == st.end()) cout << -1 << endl;
            else cout << *iter << endl;
        }
    }
}
