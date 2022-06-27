#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, X; cin >> N >> X; X--;
    string S;
    rep(i, 26) {
        rep(j, N) S += (char)('A' + i);
    }
    cout << S[X] << endl;
}