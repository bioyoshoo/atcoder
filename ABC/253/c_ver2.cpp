#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int q; cin >> q;
    multiset<ll> st;
    rep(i, q) {
        int n; cin >> n;
        if (n == 1) {
            ll x; cin >> x;
            st.insert(x);
        }
        else if (n == 2) {
            ll x, c; cin >> x >> c;
            rep(j, c) {
                auto it = st.find(x);
                if (it == st.end()) break;
                st.erase(it);
            }
        }
        else if (n == 3) {
            cout << *prev(st.end()) - *st.begin() << endl;
        }
    }
}