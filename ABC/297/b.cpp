#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    string S; cin >> S;
    int N = S.size();

    int b_bin = -1;
    int r_cnt = 0;
    bool ans = true;
    rep(i, N) {
        if (S[i] == 'B') {
            if (b_bin == -1) {
                b_bin = i % 2;
            }
            else {
                if (b_bin == (i % 2)) ans = false;
            }
        }
        else if (S[i] == 'R') {
            r_cnt++;
        }
        else if (S[i] == 'K') {
            if (r_cnt != 1) ans = false;
        }
    }

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
