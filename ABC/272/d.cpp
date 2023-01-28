#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using cord = pair<int, int>;

bool is_square(ll n) {
    return sqrt(n) == (ll)sqrt(n);
}

int main() {
    int N, M; cin >> N >> M;
    
    queue<cord> todo;
    todo.push({0, 0});
    vector<int> x_rot = {1, 1, -1, -1}, y_rot = {1, -1, 1, -1};

    vector<vector<int>> ans(N, vector<int>(N, -1));
    ans[0][0] = 0;

    while (!todo.empty()) {
        int sx, sy;
        tie(sx, sy) = todo.front();
        todo.pop();

        for (ll dx = 0; dx * dx <= M; dx++) {
            ll dyy = M - dx*dx;
            if (!is_square(dyy)) continue;

            ll dy = sqrt(dyy);

            rep(r, 4) {
                ll nx = sx + dx * x_rot[r], ny = sy + dy * y_rot[r];

                if (0 > nx || nx >= N) continue;
                if (0 > ny || ny >= N) continue;
                if (ans[nx][ny] != -1) continue;

                ans[nx][ny] = ans[sx][sy] + 1;
                todo.push({nx, ny});
            }
        }
    }
    
    rep(i, N) {
        rep(j, N) {
            cout << ans[i][j] << " ";
            if (j == N - 1) cout << endl;
        }
    }
}
