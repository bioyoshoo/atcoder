#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    string T; cin >> T;
    string S = "110";
    ll V = 1e10;

    ll ans = 0;
    if (T == "1") ans = 2e10;
    else if (T == "0") ans = 1e10;
    else {
        for (int s = 0; s < 3; s++) {
            ll a = (T.size() + s + 2) / 3;
            ll add = V - a + 1;

            bool ok = true;
            for (int i = 0; i < N; i++) {
                if (T[i] != S[(s + i) % 3]) ok = false;
            }
            if (ok) ans += add;
        }
    }
    cout << ans << endl;
}