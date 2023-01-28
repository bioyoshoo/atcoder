#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using Interval = pair<int, int>;

bool cmp(const Interval &a, const Interval &b) {
    return a.second < b.second;
}

int main() {
    int N; cin >> N;
    vector<Interval> T(N);
    rep(i, N) cin >> T[i].first >> T[i].second;

    sort(T.begin(), T.end(), cmp);

    int ans = 0;
    int cur = -1;

    rep(i, N) {
        if (cur <= T[i].first) {
            ans++;
            cur = T[i].second;
        }
    }

    cout << ans << endl;
}