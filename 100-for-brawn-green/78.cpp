#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int M, N, K; cin >> M >> N >> K;
    vector<vector<int>> J(M+1, vector<int>(N+1)), O(M+1, vector<int>(N+1)), I(M+1, vector<int>(N+1));

    rep(i, M) {
        rep(j, N) {
            char c; cin >> c;
            if (c == 'J') J[i+1][j+1] = 1;
            else if (c == 'O') O[i+1][j+1] = 1;
            else I[i+1][j+1] = 1;
        }
    }

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            J[i][j] += J[i][j - 1]; O[i][j] += O[i][j - 1]; I[i][j] += I[i][j - 1];
        }
    }

    for (int j = 1; j <= N; j++) {
        for (int i = 1; i <= M; i++) {
            J[i][j] += J[i - 1][j]; O[i][j] += O[i - 1][j]; I[i][j] += I[i - 1][j];
        }
    }

    rep(k, K) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        int j = J[c][d] - J[c][b - 1] - J[a - 1][d] + J[a - 1][b - 1];
        int o = O[c][d] - O[c][b - 1] - O[a - 1][d] + O[a - 1][b - 1];
        int i = I[c][d] - I[c][b - 1] - I[a - 1][d] + I[a - 1][b - 1];
        cout << j << " " << o << " " << i << endl;
    }
}
