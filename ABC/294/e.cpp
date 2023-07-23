#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll L; int N1, N2; cin >> L >> N1 >> N2;
    map<ll, vector<pair<int, int>>> events;

    ll pos = 0;
    ll value, l;
    rep(i, N1) {
        cin >> value >> l;
        events[pos].push_back(make_pair(0, value));
        pos += l;
    }
    events[pos].push_back(make_pair(0, -1));

    pos = 0;
    rep(i, N2) {
        cin >> value >> l;
        events[pos].push_back(make_pair(1, value));
        pos += l;
    }
    events[pos].push_back(make_pair(1, -1));

    ll ans = 0;
    ll pos0 = 0, pos1 = 0;
    int v0 = -1, v1 = -1;
    for (auto [p, val]: events) {

        if (v0 == v1) {
            ans += abs(p - max(pos0, pos1));
        }

        // update events of row0 and row1
        for (auto [c, v]: val) {
            if (c == 0) {
                pos0 = p; v0 = v;
            }
            else if (c == 1) {
                pos1 = p; v1 = v;
            }
        }
    }
    
    cout << ans << endl;
}