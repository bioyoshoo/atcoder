#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<int> C(N); rep(i, N) cin >> C[i];
    sort(C.begin(), C.end());
    for (int i = 1; i < N; i++) C[i] += C[i - 1];

    int Q; cin >> Q;
    rep(i, Q) {
        int x; cin >> x;
        int ans = lower_bound(C.begin(), C.end(), x + 1) - C.begin();
        cout << ans << endl;
    }
}
