#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, M; cin >> N >> M;
    vector<vector<int>> T(N, vector<int>(N));
    rep(i, M) {
        int x, y; cin >> x >> y; x--; y--;
        T[x][y] = 1; T[y][x] = 1;
    }

    int ans = 0;
    for (ll i = 0; i < (1LL << N); i++) {
        vector<int> people;
        rep(j, N) {
            if (i & (1LL << j)) people.push_back(j);
        }
        int n = people.size();
        bool flag = true;
        for (int a = 0; a < n; a++) {
            for (int b = a + 1; b < n; b++) {
                if (T[people[a]][people[b]] == 0) flag = false;
            }
        }
        if (flag) ans = max(ans, n);
    }
    cout << ans << endl;
}