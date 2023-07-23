#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, Q; cin >> N >> Q;

    int cnt = 1;
    set<int> st;
    rep(i, Q) {
        int q; cin >> q;
        if (q == 1) {
            st.insert(cnt);
            cnt++;
        }
        else if (q == 2) {
            int x; cin >> x;
            st.erase(x);
        }
        else {
            cout << *begin(st) << endl;
        }
    }
}