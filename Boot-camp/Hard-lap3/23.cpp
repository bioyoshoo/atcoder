#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    string S; cin >> S;
    int N = S.size();
    reverse(S.begin(), S.end());

    bool ans = true;
    for (int i = 0; i < N;) {
        if (S.substr(i, 5) == "maerd") i += 5;
        else if (S.substr(i, 7) == "remaerd") i += 7;
        else if (S.substr(i, 5) == "esare") i += 5;
        else if (S.substr(i, 6) == "resare") i += 6;
        else {
            ans = false;
            break;
        }
    }
    if (ans) cout << "YES" << endl;
    else cout << "NO" << endl;
}