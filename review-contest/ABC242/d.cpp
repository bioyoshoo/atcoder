#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

char next(char c, int step) {
    string S = "ABC";
    int i = ((int)(c - 'A') + step) % 3;
    return S[i];
}

string S;
char rec(ll t, ll k) {
    if (t == 0) return S[k];
    if (k == 0) {
        if (t % 3 == 0) return S[0];
        else if (t % 3 == 1) return next(S[0], 1);
        else return next(S[0], 2);
    }

    char c = rec(t - 1, k / 2);

    if (k % 2 == 0) return next(c, 1);
    else return next(c, 2);
}

int main() {
    cin >> S;
    int Q; cin >> Q;
    rep(i, Q) {
        ll t, k; cin >> t >> k; k--;
        cout << rec(t, k) << endl;
    }
}
