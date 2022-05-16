#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    vector<pair<ll, ll>> cord(N);
    set<pair<ll, ll>> st;
    map<ll, vector<int>> X, Y;
    for (int i = 0; i < N; i++) {
        ll x, y; cin >> x >> y;
        cord.at(i) = {x, y};
        st.insert({x, y});
        X[x].push_back(i); Y[y].push_back(i);
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int x1, y1;
        tie(x1, y1) = cord.at(i);
        for (auto j: Y[y1]) {
            if (cord[j].first <= x1) continue;
            int x2 = cord[j].first;
            for (auto k: X[x1]) {
                if (cord[k].second <= y1) continue;
                int y2 = cord[k].second;
                if (st.count({x2, y2})) ans++;
            }
        }
    }
    cout << ans << endl;
}