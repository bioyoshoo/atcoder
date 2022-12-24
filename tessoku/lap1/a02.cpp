#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, X; cin >> N >> X;
    set<int> st;
    rep(i, N) {
        int a; cin >> a;
        st.insert(a);
    }

    if (st.count(X)) cout << "Yes" << endl;
    else cout << "No" << endl;
}