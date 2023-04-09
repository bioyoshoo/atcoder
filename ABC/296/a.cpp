#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    string S; cin >> S;
    bool ans = true;
    rep(i, N - 1) {
        if (S[i] == S[i + 1]) ans = false;
    }

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}