#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    string S; cin >> S;
    int n = S.size();

    int cnt = 0, ans = 0;
    rep(i, n) {
        if (S[i] == '0') {
            cnt++;
        }
        else {
            ans += (cnt + 1) / 2;
            cnt = 0;

            ans++;
        }
    }
    ans += (cnt + 1) / 2;

    cout << ans << endl;
}
