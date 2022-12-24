#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    string S; cin >> S;
    int n = S.size();
    int ans = -1;
    rep(i, n) {
        if (S[i] == 'a') ans = i + 1;
    }
    cout << ans << endl;
}