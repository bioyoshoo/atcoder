#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int L, R; cin >> L >> R;
    string S = "atcoder";
    cout << S.substr(L - 1, R - L + 1) << endl;
}