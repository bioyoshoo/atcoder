#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using Interval = pair<ll, ll>;

bool cmp(const Interval &a, const Interval &b) {
    return a.second < b.second;
}

int main() {
    int N; cin >> N;
    vector<Interval> cord;
    for (int i = 0; i < N; i++) {
        ll x, l; cin >> x >> l;
        cord.push_back({x - l, x + l});
    }
    sort(cord.begin(), cord.end(), cmp);

    ll ans = 0;
    ll cur = -1e10;
    for (int i = 0; i < N; i++) {
        ll start = cord[i].first, end = cord[i].second;
        if (cur <= start) {
            ans++;
            cur = end;
        }
    }
    cout << ans << endl;
}