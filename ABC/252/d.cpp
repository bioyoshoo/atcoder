#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<int> A(N);
    map<int, int> mp;
    rep(i, N) {
        int a;
        cin >> a;
        mp[a]++;
        A.at(i) = a;
    }

    ll ans = 0;
    ll same = 0;
    for (auto m: mp) same += m.second * (m.second - 1) / 2;
    for (int i = 0; i < N; i++) {
        int n = mp[A[i]];
        same -= n - 1;
        mp[A[i]]--;
        ll sub = same;
        if (mp[A[i]] > 1) sub -= mp[A[i]] * (mp[A[i]] - 1) / 2;
        ll m = N - i - 1 - mp[A[i]];
        ans += max(0LL, max(0LL, m * (m - 1) / 2) - sub);
    }
    cout << ans << endl;
}