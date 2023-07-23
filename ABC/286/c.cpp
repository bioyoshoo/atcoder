#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    ll A, B; cin >> A >> B;
    string S; cin >> S;

    ll ans = 1e18;
    // start position
    rep(s, N) {
        ll cand = A * s;

        string T = "";
        for (int i = s; i < N; i++) T += S[i];
        for (int i = 0; i < s; i++) T += S[i];

        rep(i, N / 2) {
            char a = T[i], b = T[N - 1 - i];
            if (a != b) {
                cand += B;
            }
        }
        ans = min(ans, cand);
    }

    cout << ans << endl;
}
