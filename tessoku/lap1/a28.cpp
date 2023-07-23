#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const int mod = 10000;

int main() {
    int N; cin >> N;
    
    int ans = 0;
    rep(i, N) {
        char t; int a; cin >> t >> a;
        if (t == '+') ans += a;
        else if (t == '-') ans -= a;
        else if (t == '*') ans *= a;

        if (ans < 0) ans += mod;
        ans %= mod;

        cout << ans << endl;
    }
}