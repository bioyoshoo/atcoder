#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<int> A(N); rep(i, N) cin >> A[i];

    vector<int> ans(N);

    vector<int> V;
    set<int> st;
    rep(i, N) {
        if (!st.count(A[i])) {
            V.push_back(A[i]);
            st.insert(A[i]);
        }
    }
    sort(V.begin(), V.end());

    rep(i, N) {
        int cnt = (int)V.size() - (upper_bound(V.begin(), V.end(), A[i]) - V.begin());
        ans[cnt]++;
    }

    rep(i, N) cout << ans[i] << endl;
}