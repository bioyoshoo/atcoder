#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll N; cin >> N;

    string ans = "";
    if (N == 0) ans = "0";
    else {
        while (N != 0) {
        ll res = N % (-2);
        if (res < 0) res += 2;

        if (res == 0) ans += "0";
        else ans += "1";
        N -= res;
        N /= -2;
        }
        reverse(ans.begin(), ans.end());
    }
    cout << ans << endl;
}