#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    string S; cin >> S;
    int n = S.size();

    bool ans = true;
    
    if (n != 8) ans = false;

    rep(i, n) {

        if (i == 0 || i == n - 1) {
            int c = S[i] - 'A';
            if (c >= 0 && c <= (int)('Z' - 'A')) continue;
            else ans = false;
        }
        else {
            int d = S[i] - '0';
            if (i == 1 && d == 0) ans = false;
             
            if ((d >= 0) & (d <= 9)) continue;
            else ans = false;
        }
    }

    if (ans == true) cout << "Yes" << endl;
    else cout << "No" << endl;
}