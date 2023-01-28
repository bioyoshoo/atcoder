#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<vector<int>> T(1501, vector<int>(1501));
    rep(i, N) {
        int x, y; cin >> x >> y;
        T[x][y] += 1;
    }

    for (int i = 0; i <= 1500; i++) for (int j = 1; j <= 1500; j++)  T[i][j] += T[i][j - 1];
    for (int j = 0; j <= 1500; j++) for (int i = 1; i <= 1500; i++)  T[i][j] += T[i - 1][j];

    int Q; cin >> Q;
    rep(i, Q) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        cout << T[c][d] - T[c][b - 1] - T[a - 1][d] + T[a - 1][b - 1] << endl;
    }
}
