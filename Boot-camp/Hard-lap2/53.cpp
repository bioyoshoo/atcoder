#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int64_t, int64_t>> V(N);
    for (int i = 0; i < N; i++) {
        int64_t x, y; cin >> x >> y;
        V.at(i) = {x, y};
    }
    map<pair<int64_t, int64_t>, int64_t> mp;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            int64_t dx = V[i].first - V[j].first;
            int64_t dy = V[i].second - V[j].second;
            pair<int64_t, int64_t> p = {dx, dy};
            mp[p]++;
        }
    }
    int64_t ans;
    if (mp.size() == 0) ans = 1;
    else {
        int64_t max_num = 0;
        for (auto m: mp) max_num = max(max_num, m.second);
        ans = N - max_num;
    }
    cout << ans << endl;
}