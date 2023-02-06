#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, M; cin >> N >> M;
    vector<string> S(N), T(M);

    rep(i, N) {
        string s; cin >> s;
        S[i] = s.substr(3, 3);
    }

    rep(i, M) {
        string t; cin >> t;
        T[i] = t;
    }

    int ans = 0;
    rep(i, N) {
        rep(j, M) {
            if (S[i] == T[j]) {
                ans++;
                break;
            }
        }
    }

    cout << ans << endl;
}