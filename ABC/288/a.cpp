#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    string S; cin >> S;
    string ans = "";
    for (auto c: S) {
        if (c == '1') ans += '0';
        else ans += '1';
    }
    cout << ans << endl;
}