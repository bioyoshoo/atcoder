#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<vector<int>> V(N, vector<int>(2));
    set<pair<int, int>> st;
    rep(i, N) {
        int x, y; cin >> x >> y;
        V[i][0] = x; V[i][1] = y;
        st.insert({x, y});
    }
    
    int ans = 0;
    rep(i, N) {
        rep(j, N) {
            int x1, x2, y1, y2;
            x1 = V[i][0]; y1 = V[i][1];
            x2 = V[j][0]; y2 = V[j][1];

            if (!(x1 <= x2 && y1 <= y2)) continue;

            int dx = x2 - x1, dy = y2 - y1;

            int x3, x4, y3, y4;
            x3 = x1 - dy; y3 = y1 + dx;
            x4 = x2 - dy; y4 = y2 + dx;
            if (x3 < 0 || 5000 < x3) continue;
            if (y3 < 0 || 5000 < y3) continue;
            if (x4 < 0 || 5000 < x4) continue;
            if (y4 < 0 || 5000 < y4) continue;
            if (!st.count({x3, y3}) || !st.count({x4, y4})) continue;

            ans = max(ans, dx * dx + dy * dy);
        }
    }
    cout << ans << endl;
}