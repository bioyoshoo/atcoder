#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, D; cin >> N >> D;
    vector<pair<int, int>> XY(N);
    rep(i, N) {
        int x, y; cin >> x >> y;
        XY[i] = make_pair(x, y);
    }

    sort(XY.begin(), XY.end());

    priority_queue<int> pq;
    int ans = 0;
    int cur = 0;
    for (int d = 1; d <= D; d++) {
        while (cur < N && XY[cur].first == d) {
            pq.push(XY[cur].second);
            cur++;
        }

        if (pq.empty()) continue;

        ans += pq.top();
        pq.pop();
    }

    cout << ans << endl;
}
