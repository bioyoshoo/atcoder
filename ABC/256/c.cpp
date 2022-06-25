#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    vector<int> H(3), W(3);
    cin >> H[0] >> H[1] >> H[2] >> W[0] >> W[1] >> W[2];
    vector<vector<int>> T(3, vector<int>(3));
    int ans = 0;
    for (int c00 = 1; c00 <= 30; c00++) {
        for (int c01 = 1; c01 <= 30; c01++) {
            for (int c10 = 1; c10 <= 30; c10++) {
                for (int c11 = 1; c11 <= 30; c11++) {
                    T[0][0] = c00;
                    T[0][1] = c01;
                    T[1][0] = c10;
                    T[1][1] = c11;

                    bool flag = true;
                    rep(j, 2) {
                        T[2][j] = W[j] - T[0][j] - T[1][j];
                        if (!(1 <= T[2][j] && T[2][j] <= 30)) flag = false;
                    }
                    rep(j, 2) {
                        T[j][2] = H[j] - T[j][0] - T[j][1];
                        if (!(1 <= T[j][2] && T[j][2] <= 30)) flag = false;
                    }
                    if (!flag) continue;
                    
                    if (W[2] - T[0][2] - T[1][2] == H[2] - T[2][0] - T[2][1]) {
                        if (1 <= W[2] - T[0][2] - T[1][2] && W[2] - T[0][2] - T[1][2] <= 30) ans++;
                    }
                } 
            }
        }
    }
    cout << ans << endl;
}