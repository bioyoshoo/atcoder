#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N;
    ll P, Q, R;
    cin >> N >> P >> Q >> R;
    vector<ll> A;
    A.push_back(0);
    rep(i, N) {
        int a; cin >> a; A.push_back(a);
    }
    for (int i = 1; i < N + 1; i++) A[i] += A[i - 1];

    set<ll> st;
    rep(i, N + 1) st.insert(A[i]);

    bool ans = false;
    for (int i = 1; i < N + 1; i++) {
        if (!st.count(A[i - 1] + P)) continue;
        if (!st.count(A[i - 1] + P + Q)) continue;
        if (!st.count(A[i - 1] + P + Q + R)) continue;
        ans = true;
        break;
    }

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}