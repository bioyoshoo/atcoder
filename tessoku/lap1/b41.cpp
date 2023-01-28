#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int X, Y; cin >> X >> Y;
    vector<pair<int, int>> ans;

    int x = X, y = Y;
    while (true) {

        if (x == 1 && y == 1) break;
        ans.push_back({x, y});
        
        if (x >= y) x = x - y;
        else if (x < y) y = y - x;
    }

    reverse(ans.begin(), ans.end());

    cout << ans.size() << endl;
    rep(i, (int)ans.size()) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}
