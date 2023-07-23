#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)


int dist(pair<int, int> p1, pair<int, int> p2) {
    return abs(p2.first - p1.first) + abs(p2.second - p1.second);
}

int main() {
    int R, C; cin >> R >> C;
    vector<vector<char>> B(R, vector<char>(C));
    rep(r, R) rep(c, C) cin >> B[r][c];
    vector<vector<char>> ans = B;


    rep(i, R) rep(j, C) {
        if (B[i][j] != '#' && B[i][j] != '.') {
            int x = (int)(B[i][j] - '0');
            for (int a = -x; a <= x; a++) {
                for (int b = -x; b <= x; b++) {
                    int ni = i + a, nj = j + b;
                    
                    if (ni < 0 || ni >= R) continue;
                    if (nj < 0 || nj >= C) continue;

                    int d = dist(make_pair(i, j), make_pair(ni, nj));
                    if (d <= x) ans[ni][nj] = '.';
                }
            }
        }
    }

    rep(i, R) rep(j, C) {
        cout << ans[i][j];
        if (j == C - 1) cout << endl;
    }
}