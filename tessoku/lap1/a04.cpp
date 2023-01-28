#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;

    string ans = "";
    for (int i = 9; i >= 0; i--) {
        if (N & (1 << i)) ans += '1';
        else ans += '0';
    }

    cout << ans << endl;
}