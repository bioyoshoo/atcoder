#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

vector<vector<int>> create_table(vector<vector<int>> T, int skip_row, int skip_col) {
    int n = T.size();
    vector<vector<int>> res;
    rep(i, n) {
        if (i == skip_row) continue;
        vector<int> col;
        rep(j, n) {
            if (j == skip_col) continue;
            col.push_back(T[i][j]);
        }
        res.push_back(col);
    }
    return res;
}

int rec(vector<vector<int>> T, int x) {
    if (x == 1) return 0;
    int n = T.size();
    int sx = -1, sy = -1;
    rep(i, n) rep(j, n) {
        if (T[i][j] == x) {
            sx = i; sy = j;
        }
    }
    vector<vector<int>> U = create_table(T, sx, sy);
    return rec(U, x - 1) + (n - 1 - sx) + (n - 1 - sy);
}

int main() {
    int N; cin >> N;
    vector<vector<int>> P(N, vector<int>(N));
    rep(i, N) rep(j, N) cin >> P[i][j];

    cout << rec(P, N) << endl;
}
