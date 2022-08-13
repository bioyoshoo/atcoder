#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n; cin >> n;
    vector<int> A(n), B(n);
    rep(i, n) cin >> A[i] >> B[i];

    vector<int> cnt(1e6 + 2);
    rep(i, n) {
        cnt[A[i]]++;
        cnt[B[i] + 1]--;
    }

    for (int i = 1; i < 1e6 + 2; i++) cnt[i] += cnt[i - 1];
    int ans = 0;
    for (int i = 0; i < 1e6 + 1; i++) ans = max(ans, cnt[i]);
    cout << ans << endl;
}