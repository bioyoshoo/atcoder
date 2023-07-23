#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    string S; cin >> S;
    int n = S.size();

    rep(i, n) {
        if (S[i] >= 'a' && S[i] <= 'z') continue;
        else {
            cout << i + 1 << endl;
            return 0;
        }
    }
}