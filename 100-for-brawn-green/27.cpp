#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int m, n;
int T[100][100];
int dp[100][100];
vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};

int rec(int x, int y) {
    int mx = -1;
    rep(i, 4) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || n - 1 < nx) continue;
        if (ny < 0 || m - 1 < ny) continue;
        if (T[nx][ny] != 1) continue;
        if (dp[nx][ny] != -1) continue;
        mx = max(mx, rec(nx, ny) + 1);
    }
    if (mx == -1) return dp[x][y] = 1;
    else return dp[x][y] = mx;
}

int main() {
    cin >> m >> n;
    rep(i, n) rep(j, m) cin >> T[i][j];

    int ans = -1;
    rep(sx, n) {
        rep(sy, m) {
            if (T[sx][sy] != 1) continue;
            memset(dp, -1, sizeof(dp));
            int cand = rec(sx, sy);
            ans = max(ans, cand);
        }
    }

    cout << ans << endl;
}