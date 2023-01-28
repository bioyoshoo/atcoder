#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    string S; cin >> S;

    bool ans = false;
    for (int i = 0; i < N - 2; i++) {
        if (S[i] == S[i + 1] && S[i + 1] == S[i + 2]) ans = true;
    }

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}