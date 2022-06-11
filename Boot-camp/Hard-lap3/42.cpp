#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    string S; cin >> S;

    int L = 0;
    string forward_pad = "", back_pad = "";
    rep(i, N) {
        if (S[i] == '(') L++;
        else {
            if (L > 0) L--;
            else forward_pad += '(';
        }
    }
    rep(i, L) back_pad += ')';

    string ans = forward_pad + S + back_pad;
    cout << ans << endl;
}