#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

bool check(vector<string> T) {
    int cnt = 0;
    // row
    rep(i, 6) {
        cnt = 0;
        rep(j, 6) {
            if (T[i][j] == '#') cnt++;
        }
        if (cnt >= 4) return true;
    }
    // col
    rep(j, 6) {
        cnt = 0;
        rep(i, 6) {
            if (T[i][j] == '#') cnt++;
        }
        if (cnt >= 4) return true;
    }
    // lateral
    cnt = 0;
    rep(i, 6) {
        if (T[i][i] == '#') cnt++;
    }
    if (cnt >= 4) return true;
    
    cnt = 0;
    rep(i, 6) {
        if (T[i][5 - i] == '#') cnt++;
    }
    if (cnt >= 4) return true;

    return false;
}

int main() {
    int N; cin >> N;
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    rep(i, N) rep(j, N) {
        if (i + 5 >= N) continue;
        if (j + 5 >= N) continue;

        vector<string> T(6);
        rep(a, 6) rep(b, 6) T[a] += S[i + a][j + b];

        if (check(T)) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}
