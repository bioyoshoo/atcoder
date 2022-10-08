#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

pair<int, int> get_size(vector<vector<int>> T) {
    int m = T.size(), n = T[0].size();
    return make_pair(m, n);
}

vector<vector<bool>> check(vector<vector<int>> T) {
    int m, n; tie(m, n) = get_size(T);
    vector<vector<bool>> res(m, vector<bool>(n, true));
    rep(i, m) {
        for (int L = 0; L < n;) {
            int R = L + 1;
            while (R < n && T[i][L] == T[i][R]) R++;
            if ((T[i][L] != -1) && (R - L >= 3)) {
                for (int j = L; j < R; j++) res[i][j] = false;
            }
            L = R;
        }
    }
    return res;
}

int score(vector<vector<int>> T, vector<vector<bool>> B) {
    int res = 0;
    int m, n; tie(m, n) = get_size(T);
    rep(i, m) {
        rep(j, n) {
            if (B[i][j] == false && T[i][j] != -1) res += T[i][j];
        }
    }
    return res;
}

void update(vector<vector<int>> &T, vector<vector<bool>> B) {
    int m, n; tie(m, n) = get_size(T);
    rep(j, n) {
        for (int L = m - 1; L >= 0; L--) {
            int R = L;
            while (R > 0 && B[R][j] == false) R--;

            if (R == 0 && B[R][j] == false) T[L][j] = -1;
            else T[L][j] = T[R][j];

            if (L != R) {
                T[R][j] = -1; B[R][j] = false;
            }
        }
    }
}

int main() {
    vector<int> V;
    while (true) {
        int H; cin >> H;
        if (H == 0) break;

        vector<vector<int>> T(H, vector<int>(5));
        rep(i, H) rep(j, 5) cin >> T[i][j];

        int ans = 0;
        while (true) {
            vector<vector<bool>> B = check(T);

            int p = score(T, B);
            if (p == 0) break;

            ans += p;

            update(T, B);
        }

        V.push_back(ans);
    }
    for (auto v: V) cout << v << endl;
}
