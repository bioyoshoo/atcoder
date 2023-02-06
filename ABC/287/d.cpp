#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    string S, T; cin >> S >> T;
    int n = S.size(), m = T.size();

    int left = 0;
    rep(i, m) {
        if (S[i] == T[i]) left = i + 1;
        else if (S[i] == '?' || T[i] == '?') left = i + 1;
        else break;
    }

    // x = left 以降はマッチ起こらない

    int right = m;
    rep(i, m) {
        if (S[n - 1 - i] == T[m - 1 - i]) right = m - i - 1;
        else if (S[n - 1 - i] == '?' || T[m - 1 - i] == '?') right = m - i - 1;
        else break;
    }

    // x = right 以降にしかマッチ起こらない

    rep(x, m + 1) {
        if (x <= left && x >= right) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}