#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    string S, T; cin >> S >> T;
    int N = S.size();
    vector<vector<int>> table(26, vector<int>(26));
    
    for (int i = 0; i < N; i++) table[S[i] - 'a'][T[i] - 'a'] = 1;

    bool flag = true;
    rep(i, 26) {
        int sum = 0;
        rep(j, 26) sum += table[i][j];
        if (sum > 1) flag = false;
    }
    rep(j, 26) {
        int sum = 0;
        rep(i, 26) sum += table[i][j];
        if (sum > 1) flag = false;
    }

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}