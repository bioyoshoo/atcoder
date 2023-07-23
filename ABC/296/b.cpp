#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int rowname(int i) {
    return 8 - i;
}

char colname(int j) {
    return (char)((int)'a' + j);
}

int main() {
    vector<string> S(8);
    rep(i, 8) cin >> S[i];

    rep(i, 8) rep(j, 8) {
        if (S[i][j] == '*') {
            cout << colname(j);
            cout << rowname(i);
            cout << endl;
            return 0;
        }
    }
}