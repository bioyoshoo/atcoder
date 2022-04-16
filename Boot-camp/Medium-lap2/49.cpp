#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    map<int64_t, int64_t> mp;
    for (int i = 0; i < N; i++) {
        int64_t a;
        cin >> a;
        mp[a]++;
    }

    priority_queue<pair<int64_t, int64_t>> pq;
    for (auto m: mp) pq.push({m.first, m.second});
    
    vector<int64_t> ans;
    while (ans.size() < 2 && pq.size() > 0) {
        int64_t n, time;
        tie(n, time) = pq.top();
        if (time >= 2) {
            ans.push_back(n);
            time -= 2;
            pq.pop();
            pq.push({n, time});
        }
        else pq.pop();
    }

    if (ans.size() == 2) cout << ans[0] * ans[1] << endl;
    else cout << 0 << endl;
}