#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int dist(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
    int H, W; cin >> H >> W;
    vector<string> S(H);
    rep(i, H) cin >> S[i];

    vector<pair<int, int>> cord;
    rep(i, H) {
        rep(j, W) {
            if (S[i][j] == 'o') cord.push_back({i, j});
        }
    }

    int ans = dist(cord[0], cord[1]);
    cout << ans << endl;
}