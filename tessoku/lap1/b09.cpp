#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<vector<int>> T(1502, vector<int>(1502));
    rep(i, N) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        T[a + 1][b + 1] += 1; T[a + 1][d + 1] -= 1, T[c + 1][b + 1] -= 1; T[c + 1][d + 1] += 1;
    }

    for (int i = 0; i <= 1501; i++) for (int j = 1; j <= 1501; j++) T[i][j] += T[i][j - 1];
    for (int j = 0; j <= 1501; j++) for (int i = 1; i <= 1501; i++) T[i][j] += T[i - 1][j];

    int ans = 0;
    for (int i = 0; i <= 1500; i++) for (int j = 0; j <= 1500; j++) {
        if (T[i][j] > 0) ans++;
    }

    cout << ans << endl;
}
